#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;

int main() {
    ll T; cin >> T;
    rep(ii,T){
        ll N,K; cin >> N >> K;
        ll a[N];
        rep(i,N){
            ll b; cin >> b;
            a[i] = (i+1)-b;
            //cout << a[i] << " ";
        }
        //cout << endl;
        ll dp[N+1][N+1];
        rep(i,N+1){
            rep(j,N+1) dp[i][j] = 0;
        }
        rep(i,N){
            rep(j,N+1){
                dp[i+1][j] = dp[i][j];
            }
            ll s = a[i];
            if(s<0) continue;
            ll k = 0;
            rep(j,s+1){
                if(i-(s-j)>=0) k = max(k,dp[i-(s-j)][j]);
            }
            dp[i+1][s] = min(k+1,(ll)i-s+1);
            //cout <<s << endl;
            //cout << dp[i+1][s] << endl;
        }
        ll ans = -1;
        rep(i,N+1){
            if(dp[N][i]>=K){
                ans = i; break;
            }
        }
        cout << ans << endl;
    }
    //cout << ans << endl;
}