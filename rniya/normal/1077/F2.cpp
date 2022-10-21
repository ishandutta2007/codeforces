#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,x; cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(x+1,-INF));
    dp[0][0]=0;
    vector<deque<int>> deq(x+1);
    deq[0].emplace_back(0);
    for (int i=0;i<n;++i){
        for (int j=0;j<=x;++j){
            if (!deq[j].empty()){
                if (j+1<=x) dp[i+1][j+1]=max(dp[i+1][j+1],dp[deq[j].front()][j]+a[i]);
                if (deq[j].front()==i+1-k) deq[j].pop_front();
            }
            while(!deq[j].empty()&&dp[deq[j].back()][j]<=dp[i+1][j]) deq[j].pop_back();
            deq[j].push_back(i+1);
        }
    }
    ll ans=-INF;
    for (int i=n+1-k;i<=n;++i) ans=max(ans,dp[i][x]);
    cout << (ans<0?-1:ans) << '\n';
}