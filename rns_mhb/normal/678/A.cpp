#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", k *  (n / k + 1));
    return 0;
}