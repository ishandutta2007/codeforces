#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
int dp[1000000];
void pre(int v=1,int pa=-1)
{
    dp[v]=1;
    int num=0;
    for (auto u:adj[v]){
        if (u==pa)continue;
        pre(u,v);
        dp[v]=max(dp[v],dp[u]+1);
        num++;
    }
    if (num>1)dp[v]+=num-1;
}
int ret;
void dfs(int v=1,int pa=-1,int up=0)
{
    int num=(up>0);
    int newUp;
    int mx1=up;
    int mx2=0;
    int A=up,id1=0;
    int B=0,id2=0;
    for (auto u:adj[v]) {
        if (u==pa)continue;
        num++;
        if (dp[u]>A) {
            swap(B,A);swap(id1,id2);
            A=dp[u];
            id1=u;
        } else if (dp[u]>B){
            B=dp[u];
            id2=u;
        }
    }

    for (auto u:adj[v]) {
        if (u==pa)continue;
        if (u==id1) {
            newUp = B+1+((num>2)?(num-2):0);
        } else {
            newUp = A+1+((num>2)?(num-2):0);
        }
        dfs(u,v,newUp);
        if (dp[u]>mx1){
            mx2=mx1;
            mx1=dp[u];
        } else if (dp[u]>mx2) {
            mx2=dp[u];
        }
    }
    ret=max(ret,mx1+mx2+1+((num>2)?(num-2):0));
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ret=0;
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)adj[i].clear(),dp[i]=0;
        for (int i=1;i<n;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int v = 1;
        pre(v,-1);
        dfs(v,-1,0);
        printf("%d\n",ret);
    }
}