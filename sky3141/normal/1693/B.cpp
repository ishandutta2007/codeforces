#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200010;
int h[N], e[N], ne[N], idx;
LL l[N], r[N];
int cnt = 0;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

LL dfs(int u)
{
    if(h[u] == -1)
    {
        cnt ++;
        return r[u];
    }
    LL maxv = 0;
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        maxv += dfs(j);
    }
    if(l[u] > maxv)
    {
        maxv = r[u];
        cnt ++;
    } 
    
    return min(r[u], maxv);
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
        for(int i=2;i<=n;i++)
        {
            int x;
            scanf("%d", &x);
            add(x, i);
        }
        for(int i=1;i<=n;i++) scanf("%lld%lld", &l[i], &r[i]);
        cnt = 0;
        dfs(1);
        printf("%d\n", cnt);
    }
    return 0;
}