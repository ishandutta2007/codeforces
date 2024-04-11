#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;
const ll mod = 998244353;

int n, num[N];
ll dp[N][N * N];
ll fac[N], facinv[N];
int cnt[N];
int nzcnt = 0;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

bool check(int x, int k){
    ll now = comb(cnt[x], k);
//    cout << "We choose " << k << " " << x << "s,    " << dp[k][x*k] << " " << now << endl;

    return dp[k][x * k] == now;
}

int main(){

    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        if(cnt[num[i]] == 0) nzcnt ++;
        cnt[num[i]] ++;
    }

    if(nzcnt == 1 || nzcnt == 2) return !printf("%d", n);

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int k = i; k >= 1; k--){
            for(int j = 0; j <= 10000; j++){
                if(j - num[i] >= 0) dp[k][j] = (dp[k][j] + dp[k-1][j-num[i]]) % mod;
            }
        }
    }


    int res = 1;
    for(int i = 1; i <= 100; i++){
        for(int j = 2; j <= cnt[i]; j++){
            if(check(i, j)) res = max(res, j);
        }
    }
    cout << res << endl;
}