#include <stdio.h>
#include <math.h>

int main() {

    float a, b, c;
    float delta, x1, x2;

    FILE *inputFile, *outputFile;

    // Open the input file
    inputFile = fopen("equations.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening the input file!");
        return 1;
    }

    // Open the output file
    outputFile = fopen("solutions.txt", "w");

    if (outputFile == NULL) {
        printf("Error opening the output file!");
        fclose(inputFile);
        return 1;
    }

    // Read the coefficients
    while (fscanf(inputFile, "%f %f %f", &a, &b, &c) == 3) {

        // Calculate the discriminant
        delta = b * b - 4 * a * c;

        if (a == 0) {

            if (b != 0) {
                x1 = -c / b;
                fprintf(outputFile,
                "Linear equation: x1 = %.2f\n", x1);
            }
            else if (c == 0) {
                fprintf(outputFile,
                "Infinite number of solutions.\n");
            }
            else {
                fprintf(outputFile,
                "No solution.\n");
            }
        }

        else if (delta == 0) {

            x1 = -b / (2 * a);

            fprintf(outputFile,
            "The equation has one solution: x1 = %.2f\n", x1);
        }

        else if (delta > 0) {

            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);

            fprintf(outputFile,
            "The equation has two real solutions: x1 = %.2f and x2 = %.2f\n",
            x1, x2);
        }

        else {

            fprintf(outputFile,
            "The equation has no real solutions.\n");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Results have been saved in solutions.txt\n");

    return 0;
}