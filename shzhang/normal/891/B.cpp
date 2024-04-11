#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[25];
int x[25];
int rk[25];
int ans[25];

bool cmp(int u, int v)
{
    return a[u] < a[v];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) x[i] = i;
    sort(x + 1, x + n + 1, cmp);
    for (int i = 1; i <= n; i++) rk[x[i]] = i;
    x[n+1] = x[1];
    for (int i = 1; i <= n; i++) {
        ans[i] = a[x[rk[i]+1]];
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}