/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-12 19:03:40
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s[MAXN],u[MAXN],v[MAXN],f[MAXN];
bool used[MAXN];
struct edge
{
    int to,id;
};
vector<edge> G[MAXN];
void dfs(int v,int p)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,id=G[v][i].id;
        if(to==p||used[to]) continue;
        dfs(to,v);
        if(u[id]==v) f[id]=s[to]; else f[id]=-s[to]; 
        s[v]+=s[to];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back((edge){v[i],i});G[v[i]].push_back((edge){u[i],i});
    }
    int sum=0;
    for(int i=1;i<=n;i++) sum+=s[i];
    if(sum!=0)
    {
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    memset(used,false,sizeof(used));
    dfs(1,0);
    for(int i=0;i<m;i++)
        printf("%d\n",f[i]);
    return 0;
}