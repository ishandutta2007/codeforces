#include <cstdio>

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    printf("%d\n", N+M-1);
    for (int i = 1; i <= M; i++) printf("%d %d\n", 1, i);
    for (int i = 2; i <= N; i++) printf("%d %d\n", i, 1);
}