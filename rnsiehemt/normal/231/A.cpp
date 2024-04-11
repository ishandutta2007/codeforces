#include <cstdio>

int N, A;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        if (a+b+c > 1) A++;
    }
    printf("%d\n", A);
}