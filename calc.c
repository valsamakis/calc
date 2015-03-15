#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double n1;
    double n2;

    enum {
        PLUS, MINUS, MUL, DIV
    } op;
} data;

double plus(double a1, double a2) {
    return a1 + a2;
}

double minus(double a1, double a2) {
    return a1 - a2;
}

double mul(double a1, double a2) {
    return a1 * a2;
}

double divide_by(double a1, double a2) {
    return a1 / a2;
}

double (*op[])(double, double) = {plus, minus, mul, divide_by};

int main(int argc, char *argv[]) {

    data array[] = {
        {2, 3, PLUS},
        {4, 5, MINUS},
        {4, 3, MUL},
        {5, 3, DIV}
    };

    size_t len = sizeof (array) / sizeof (data);
    int i = 0;
    for (; i < len; i++) {
        printf("%f\n", op[array[i].op](array[i].n1, array[i].n2));
    }
    
    return 0;
}
