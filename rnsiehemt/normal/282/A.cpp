#include <cstdio>

int N, X;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char c; scanf(" %*c%c%*c", &c);
        if (c == '+') X++;
        else /* c == '-' */ X--;
    }
    printf("%d\n", X);
}