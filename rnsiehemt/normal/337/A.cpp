#include <cstdio>
#include <algorithm>

int N, M;
int a[55];
int ans = 999999999;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) scanf("%d", &a[i]);
    std::sort(a, a+M);
    for (int i = 0; i+N-1 < M; i++) ans = std::min(ans, a[i+N-1]-a[i]);
    printf("%d\n", ans);
}