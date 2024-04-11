#include <cstdio>
int n, k;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < n; j++)
            printf("%d ", (i == j ? k : 0));
}