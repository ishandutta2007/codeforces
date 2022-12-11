#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll n,m,k;
ll a[5001],b[5001],c[5001],dp[5001][5001];
pair<ll,ll> p[300000];
bool ok[5001];
vector<ll> e[5001];

int main(){
    cin>>n>>m>>k;
    rep(i,n){
        cin>>a[i+1]>>b[i+1]>>c[i+1];
    }
    rep(i,m){
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+m,greater<pair<ll,ll>>());
    rep(i,m){
        if(!ok[p[i].second]){
            ok[p[i].second]=1;
            e[p[i].first].push_back(c[p[i].second]);
        }
    }
    for(int i=1;i<=n;i++){
        if(!ok[i])e[i].push_back(c[i]);
        sort(e[i].begin(),e[i].end(),greater<ll>());
    }
    rep(i,5001)rep(j,5001)dp[i][j]=-1e18;
    dp[0][k]=0;
    for(int i=0;i<n;i++){
        for(int j=a[i+1];j+b[i+1]<=5000;j++){
            int J=j+b[i+1];
            dp[i+1][J]=dp[i][j];
            rep(k,e[i+1].size())dp[i+1][J-1-k]=max(dp[i+1][J-1-k],dp[i+1][J-k]+e[i+1][k]);
        }
    }
    ll ans=-1;
    rep(i,5001)ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
}