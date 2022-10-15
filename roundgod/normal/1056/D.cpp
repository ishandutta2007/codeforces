/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 16:42:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> G[MAXN];
int sz[MAXN];
multiset<int> ms;
void dfs(int v,int p)
{
    if(G[v].size()==1&&v!=1) sz[v]=1; else sz[v]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
int main()
{
    scanf("%d",&n);
    if(n==1) {puts("1"); return 0;}
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        G[i].push_back(x);G[x].push_back(i);
    }
    dfs(1,0);
    sort(sz+1,sz+n+1);
    for(int i=1;i<=n;i++) printf("%d ",sz[i]);
    return 0;
}