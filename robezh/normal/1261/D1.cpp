/**
 * Author:
 * Date:
 * License:
 * Source:
 * Description:
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)4005;
const ll mod = 998244353;

int n, num[N];
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
}

const int K = 2005, OFF = 2002;

int k;
int h[N];
ll dp[K][N];

void add(ll &to, ll val) {
    to += val;
    to %= mod;
}

int main(){
    init_fac();
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> h[i];
    dp[0][OFF] = 1;
    for(int i = 1; i <= n; i++) {
        for(int dif = 0; dif < N; dif++) {
            int cur = h[i], nxt = h[i % n + 1];
            if(cur == nxt) add(dp[i][dif], dp[i-1][dif] * k);
            else {
                if(dif + 1 < N) add(dp[i][dif], dp[i-1][dif+1]);
                if(dif - 1 >= 0) add(dp[i][dif], dp[i-1][dif-1]);
                add(dp[i][dif], dp[i-1][dif] * (k - 2));
            }
        }
    }
    ll res = 0;
    for(int dif = OFF + 1; dif < N; dif++) add(res, dp[n][dif]);
    cout << res << endl;

}