#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;
#define double long double

const ll mod = 1000000007;


// abm
long long pw(long long a,long long b,long long m){
    if(b==0) return 1;
    else if(b%2==0){
        long long x = pw(a,b/2,m);
        return (x*x)%m;
    }
    else{
        long long x = pw(a,b-1,m);
        return (a*x)%m;
    }
}



//mod
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N; cin >> N;
    string S; cin >> S;
    ll K = 0;
    rep(i,N){
        if(S[i]=='?') K++;
    }
    ll b = pw(3,K,mod);
    ll i3 = modinv(3,mod);
    ll dp[N+1][4];
    rep(i,N+1){
        rep(j,4) dp[i][j] = 0;
    }
    dp[0][0] = b;
    rep(i,N){
        rep(j,4) dp[i+1][j] = dp[i][j];
        if(S[i]=='a'){
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] %= mod;
        }
        if(S[i]=='b'){
            dp[i+1][2] += dp[i][1];
            dp[i+1][2] %= mod;
        }
        if(S[i]=='c'){
            dp[i+1][3] += dp[i][2];
            dp[i+1][3] %= mod;
        }
        if(S[i]=='?'){
            rep(j,3){
                dp[i+1][j+1] += (dp[i][j]*i3)%mod;
                dp[i+1][j+1] %= mod;
            }
        }
    }
    ll ans = dp[N][3];
    cout << ans << endl;
}