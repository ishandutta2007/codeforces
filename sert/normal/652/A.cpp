#include <cstdio>
int main() {
    int a, b, h0, h1;
    scanf("%d%d%d%d", &h0, &h1, &a, &b);
    h0 -= 4 * a;
    a *= 12;
    b *= 12;
    if (a >= h1 - h0) {
        printf("0");
        return 0;
    }    
    if (a <= b) {
        printf("-1");
        return 0;
    }

    printf("%d", (h1 - h0 - b - 1) / (a - b));
}