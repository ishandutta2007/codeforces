#include <cstdio>
int n, m;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; printf("\n"), i++)
        for (int j = 0; j < n; j++)
            printf("%c", (i + j < n / 2 || i + j >= n + n / 2 || i - j < -n / 2 || i - j > n / 2 ? '*' : 'D'));
}