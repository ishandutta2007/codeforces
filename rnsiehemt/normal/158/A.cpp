#include <cstdio>

int N, K;
int a[105];

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]); a[N] = 0;
    int j = 0; while (a[j] && a[j] >= a[K-1]) j++;
    printf("%d\n", j);
}