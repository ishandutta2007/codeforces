#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.begin()+k);
    vector<ll> sum(k+1,0);
    for (int i=0;i<k;++i) sum[i+1]=sum[i]+a[i];
    vector<int> offer(k+1,0);
    iota(offer.begin(),offer.end(),0);
    for (int i=0;i<m;++i){
        int x,y; cin >> x >> y;
        if (k<x) continue;
        offer[x]=min(offer[x],x-y);
    }
    vector<ll> dp(k+1,INF);
    dp[0]=0;
    for (int i=0;i<k;++i)
        for (int j=1;i+j<=k;++j)
            dp[i+j]=min(dp[i+j],dp[i]+sum[i+offer[j]]-sum[i]);
    cout << dp[k] << '\n';
}