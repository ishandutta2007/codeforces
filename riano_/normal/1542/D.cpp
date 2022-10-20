#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

ll mod = 998244353;

int main() {
    ll N; cin >> N;
    ll ans = 0;
    ll a[N];
    rep(i,N){
        char c; cin >> c;
        if(c=='-') a[i] = -1;
        else{
            ll b; cin >> b;
            a[i] = b;
        }
    }
    ll dp[N+1][N+1];
    rep(k,N){
        if(a[k]==-1) continue;
        rep(i,N+1){
            rep(j,N+1) dp[i][j] = 0;
        }
        dp[0][0] = 1;
        rep(i,N){
            rep(j,N+1){
                dp[i][j] %= mod;
                dp[i+1][j] += dp[i][j];
                if(i==k) continue;
                if(a[i]>=1&&a[i]<a[k]&&j+1<=N){
                    dp[i+1][j+1] += dp[i][j];
                }
                else if(a[i]>a[k]){
                    dp[i+1][j] += dp[i][j];
                }
                else if(a[i]==a[k]){
                    if(i<k) dp[i+1][j+1] += dp[i][j];
                    else dp[i+1][j] += dp[i][j];
                }
                else if(a[i]<0){
                    if(j!=0) dp[i+1][j-1] += dp[i][j];
                    else{
                        if(i<k) dp[i+1][j] += dp[i][j];
                    }
                }
            }
        }
        ll cnt = 0;
        rep(i,N+1){
            cnt += dp[N][i];
            //cout << i << " " << dp[N][i] << endl;
        }
        cnt %= mod;
        //cout << cnt << endl;
        ans += cnt*a[k]%mod;
    }
    ans %= mod;
    cout << ans << endl;
}