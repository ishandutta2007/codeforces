/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-07 23:01:35
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN],sz[MAXN],fa[MAXN];
int k1,k2;
vector<int> G[MAXN];
bool flag[MAXN],flag2[MAXN];
void dfs(int v,int p)
{
    fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
int descend(int v)
{
    if(flag[v]) return v;
    for(auto to:G[v])
    {
        if(to==fa[v]) continue;
        if(sz[to]) return descend(to);
    }
    return descend(fa[v]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);memset(flag,false,sizeof(flag));
        memset(flag2,false,sizeof(flag2));memset(sz,0,sizeof(sz));
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            G[u].push_back(v);G[v].push_back(u);
        }
        scanf("%d",&k1);
        for(int i=1;i<=k1;i++) 
        {
            scanf("%d",&a[i]);sz[a[i]]=1;flag[a[i]]=true;
        }
        dfs(1,0);
        scanf("%d",&k2);
        for(int i=1;i<=k2;i++)
        {
            scanf("%d",&b[i]);flag2[b[i]]=true;
        }
        printf("B %d\n",b[1]);fflush(stdout);
        int x;
        scanf("%d",&x);
        if(flag[x]) {printf("C %d\n",x); fflush(stdout); continue;}
        int v=descend(x);
        printf("A %d\n",v);fflush(stdout);
        scanf("%d",&x);
        if(flag2[x]) {printf("C %d\n",v); fflush(stdout); continue;}
        printf("C -1\n"); fflush(stdout);
    }
    return 0;
}