#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long IINF=1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,n,m; cin >> a >> n >> m;
    vector<int> rain(a+1,0);
    vector<vector<int>> umb(a+1);
    vector<ll> P(m+1,0);
    for (int i=0;i<n;++i){
        int l,r; cin >> l >> r;
        ++rain[l]; --rain[r];
    }
    for (int i=0;i<m;++i){
        int x,p; cin >> x >> p;
        umb[x].emplace_back(i+1);
        P[i+1]=p;
    }
    for (int i=0;i<a;++i) rain[i+1]+=rain[i];
    vector<vector<ll>> dp(a+1,vector<ll>(m+1,IINF));
    dp[0][0]=0;
    for (int i=0;i<a;++i){
        ll Min=IINF;
        for (int j=0;j<=m;++j){
            Min=min(Min,dp[i][j]);
            if (!rain[i]) dp[i+1][0]=min(dp[i+1][0],dp[i][j]);
            if (j) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+P[j]);
        }
        for (int x:umb[i]) dp[i+1][x]=min(dp[i+1][x],Min+P[x]);
    }
    ll ans=IINF;
    for (int j=0;j<=m;++j) ans=min(ans,dp[a][j]);
    cout << (ans==IINF?-1:ans) << '\n';
}