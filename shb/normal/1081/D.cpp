#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct edge
{
    int L,R,W;
}e[100010];

int fa[100010],s[100010];
int N,M,K;

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

bool cmp(edge a,edge b)
{
    return a.W < b.W;
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    for (int i=1;i<=K;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        s[tmp] = 1;
    }
    for (int i=1;i<=N;i++)fa[i] = i;
    for (int i=1;i<=M;i++)
    {
        scanf("%d%d%d",&e[i].L,&e[i].R,&e[i].W);
    }
    sort(e+1,e+M+1,cmp);
    for (int i=1;i<=M;i++)
    {
        int u = e[i].L, v = e[i].R;
        u = find(u);
        v = find(v);
        if (u == v) continue;
        fa[v] = u;
        s[u] += s[v];
        if (s[u] == K)
        {
            for (int j=1;j<=K;j++) printf("%d%c",e[i].W," \n"[j==N]);
            return 0;
        }
    }
}