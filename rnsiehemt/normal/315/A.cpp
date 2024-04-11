#include <cstdio>

int N;
int a[1005], b[1005], o[1005];
int ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d%d", &a[i], &b[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j && b[i] == a[j]) o[j] = 1;
    for (int i = 0; i < N; i++) ans += o[i];
    printf("%d\n", N-ans);
}