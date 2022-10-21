#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1050, mod = (int)1e9 + 7, M = (int)1e5 + 500;

bool is_lucky(int x){
    while(x > 0){
        if(x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}

ll pw(ll x, int k){
    if(k == 0) return 1;
    ll hf = pw(x, k/2);
    return k % 2 == 1 ? hf*hf%mod*x%mod : hf*hf%mod;
}

int n,k,a;
map<int, int> mp;
int num[N];
int cnt = 0;
ll fac[M], facinv[M];
ll dp[N][N];

int main(){
    fac[0] = 1;
    for(int i = 1; i < M; i++) fac[i] = fac[i-1] * i % mod;
    facinv[M-1] = pw(fac[M-1], mod-2);
    for(int i = M-2; i >= 0; i--) facinv[i] = facinv[i+1] * (i + 1) % mod;

    //cout << fac[5] * facinv[5] % mod;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(is_lucky(a)) mp[a] ++;
        else cnt ++;
    }
    n = 0;
    for(auto p : mp){
        num[++n] = p.second;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i-1][j-1] * num[i] + dp[i-1][j]) % mod;
        }
    }
    ll res = 0;
    for(int i = 0; i <= min(n, k); i++){
        if(k - i <= cnt) res += dp[n][i] * fac[cnt] % mod * facinv[k-i] % mod * facinv[cnt-k+i] % mod;
    }
    res %= mod;
    cout << res << endl;


}