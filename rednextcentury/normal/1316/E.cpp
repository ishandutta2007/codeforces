#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> b[1000000];
int a[1000000];
int s[100005][10];
int n, p, k;
ll dp[100005][130];
bool vis[100005][130];
int tot=0;
int cnt[1000];
ll DP(int i,int mask){
    if (i==n+1){
        if (mask==tot)return 0;
        return -1e18;
    }
    if (vis[i][mask])return dp[i][mask];
    vis[i][mask]=1;
    int can = ( i <= k + cnt[mask])?1:0;
    int v = b[i].second;
    dp[i][mask] = DP(i+1, mask) + can*a[v];
    for (int j=0;j<p;j++){
        if ((1<<j)&mask)continue;
        dp[i][mask]=max(dp[i][mask], DP(i+1, mask^(1<<j))+s[v][j]);
    }
    return dp[i][mask];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p>>k;
    tot = (1<<p);
    for (int i=0;i<=2*tot;i++)cnt[i] = __builtin_popcount(i);
    tot--;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<p;j++)cin>>s[i][j];
    }
    sort(b+1,b+n+1);
    reverse(b+1,b+n+1);
    cout<<DP(1,0)<<endl;
}