#include <cstdio>

int N, K;

int main()
{
    scanf("%d%d", &N, &K);
    int cur = 1, delta = K;
    for (int i = 0; i < K+1; i++) {
        printf("%d ", cur);
        cur += delta;
        if (delta < 0) delta = -delta - 1;
        else delta = -delta + 1;
    }
    for (int i = K+2; i <= N; i++)
        printf("%d ", i);
    printf("\n");
}