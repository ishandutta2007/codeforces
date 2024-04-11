#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
int mx[100000];
int dp[5001][5001];
int a[100000];
int b[100000];
int c[100000];
vector<int> adj[1000000];
int DP(int i,int j){
    if (i>n && j>=0)return 1;
    else if (i>n)return 0;
    if (j<a[i])return 0;
    if (i==n){
        if (j>=a[n])return 1;
        return 0;
    }
    if (dp[i][j]!=-1)return dp[i][j];
    return dp[i][j] = DP(i+1,j+b[i]);
}
int num[1000000];
set<pair<int,int> > s;
bool vis[1000000];
int main()
{
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i],adj[i].push_back(i);
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    if (!DP(1,k)){
        cout<<-1<<endl;
        return 0;
    }
    int cur = k;
    for (int i=1;i<=n;i++) {
        cur+=b[i];
        while(DP(i+1,cur-1))
            cur--,num[i]++;
    }
    ll ret=0;
    for (int i=n;i>=1;i--) {
        for (auto x:adj[i]) {
            s.insert({c[x],x});
        }
        while(num[i]--) {
            if (s.empty())break;
            auto x = *(--s.end());
            s.erase(--s.end());
            if (vis[x.second]){
                num[i]++;
            } else {
                vis[x.second]=1;
                ret+=x.first;
            }
        }
    }
    cout<<ret<<endl;
}