#include <cstdio>

int N, K;

int main()
{
    scanf("%d%d", &N, &K);
    if (N*(N-1)/2 <= K) printf("no solution\n");
    else for (int y = 0; y < N; y++) printf("%d %d\n", 0, y);
}