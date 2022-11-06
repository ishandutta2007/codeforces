#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 300010;
int h[N], ne[N*2], e[N*2], idx, sum[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dp(int u, int p)
{
    int l= -1, r = -1;
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(j == p) continue;

        if(~l) r = j;
        else l = j;
    }
    if(~r)
        return max(sum[r]-1 + dp(l, u), sum[l]-1+dp(r, u));
    if(~l)
        return sum[l] - 1;
    return 0;
}

int dfs(int u, int p)
{
    sum[u] = 1;
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(j == p) continue;
        sum[u] += dfs(j, u);
    }
    return sum[u];
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        memset(h, -1, sizeof h);
        idx = 0;
        int n;
        scanf("%d", &n);
        for(int i=1;i<n;i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        dfs(1, -1);
        printf("%d\n", dp(1, -1));
    }
    return 0;
}