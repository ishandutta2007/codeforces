#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
const int maxn = 200010;
struct Edge 
{
    int v, next;
}edge[maxn << 1];
int g[maxn];
int vert[maxn];
int top;
void add(int u, int v)
{
    edge[++top].v = v;
    edge[top].next = g[u];
    g[u] = top;
}

long long ans;
const int mod = 1e9 + 7;
long long int co0[maxn], co1[maxn];
int dfs(int u, int fa)
{

    if(vert[u] == 1) co1[u] = 1;
    else co0[u] = 1;
    for(int i = g[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != fa)
        {
            dfs(v, u);
            co1[u] = (co1[u] * (co0[v] + co1[v]) % mod + co0[u] * co1[v] % mod) % mod;
            co0[u] = co0[u] * (co0[v] + co1[v])% mod;
        }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        add(v, i);
        add(i, v);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &vert[i]);
    dfs(0, 0);
    printf("%I64d\n", co1[0]);
}