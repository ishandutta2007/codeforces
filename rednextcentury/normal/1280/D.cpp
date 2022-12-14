#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[1000000];
ll a[1000000];
pair<int,ll> dp[3001][3001][2];
pair<int,ll> tmp[3001][2];
ll sub[1000000];
int num[1000000];
void pre(int v=1,int p=0){
    sub[v]=a[v];
    num[v]=1;
    for (auto u:adj[v]){
        if (u==p)continue;
        pre(u,v);
        sub[v]+=sub[u];
        num[v]+=num[u];
    }
}
pair<int,ll> operator+(pair<int,ll> A,pair<int,ll> B){
    return {A.first+B.first,A.second+B.second};
}

void dfs(int v=1,int p=0){
    dp[v][0][0]={0,a[v]};
    //if (sub[v]>0)dp[v][1][1]={1,0};
    //else dp[v][1][1]={0,0};
    int sz=1;
    //for (int i=0;i<=num[v];i++) dp[v][i][0]=max(dp[v][i][0],dp[v][i][1]);
    for (auto u:adj[v]){
        if (p==u)continue;
        dfs(u,v);
        for (int i=0;i<=sz+num[u];i++)tmp[i][0]=dp[v][i][0], tmp[i][1]=dp[v][i][1];
        for (int i=0;i<=sz+num[u];i++)dp[v][i][0]=dp[v][i][1]={0,-1e16};

        for (int i=0;i<=sz;i++) {
            for (int j=0;j<=num[u];j++) {
                dp[v][j+i][0] = max(dp[v][j+i][0],tmp[i][0]+dp[u][j][0]);
            }
        }
        sz+=num[u];
    }
    for (int i=0;i<=num[v];i++) {
        //dp[v][i][0]=dp[v][i][0]+make_pair(0,a[v]);
        if (dp[v][i][0].second>0){
            dp[v][i+1][1]=max(dp[v][i+1][1],{dp[v][i][0].first+1,0});
        } else {
            dp[v][i+1][1]=max(dp[v][i+1][1],{dp[v][i][0].first,0LL});
        }
    }
    for (int i=0;i<=num[v];i++) dp[v][i][0]=max(dp[v][i][0],dp[v][i][1]);

}
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++)for (int j=0;j<=n;j++)dp[i][j][0] = dp[i][j][1] ={0,-1e16};
        for (int i=1;i<=n;i++){
            cin>>b[i];
            a[i]=b[i]-a[i];
        }
        for (int i=1;i<=n;i++)adj[i].clear();
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pre();
        dfs();
        int ret = dp[1][m][1].first;
        cout<<ret<<endl;
    }
}