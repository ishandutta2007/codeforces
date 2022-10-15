/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 23:03:49
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
int n,c[MAXN],deg[MAXN],to[MAXN],res;
vector<int> G[MAXN];
bool vis[MAXN];
void dfs(int v)
{
    if(vis[v]) return;
    vis[v]=true;
    res=min(res,c[v]);
    dfs(to[v]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    memset(vis,false,sizeof(vis));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&to[i]);
        G[i].push_back(to[i]); deg[to[i]]++;
    }
    queue<int> que;
    for(int i=1;i<=n;i++) if(deg[i]==0) que.push(i);
    while(que.size())
    {
        int p=que.front();vis[p]=true;que.pop();
        deg[to[p]]--;if(deg[to[p]]==0) que.push(to[p]);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        res=INF;
        dfs(i);ans+=res;
        //printf("%d %d\n",i,ans);
    }
    printf("%d\n",ans);
    return 0;
}