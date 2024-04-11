#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3005;
const ll mod = (ll)1e9 + 7;

int n, D;
vector<int> G[N];
ll dp[N][N], pf[N][N];
ll fac[N], facinv[N];
ll inv[N];
ll pp[N], sp[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

void calc(int v, int p) {
    for(int i = 1; i <= n + 1; i++) dp[v][i] = 1;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        calc(nxt, v);
        for(int i = 1; i <= n + 1; i++) dp[v][i] *= pf[nxt][i], dp[v][i] %= mod;
    }
    for(int i = 1; i <= n + 1; i++) pf[v][i] = (dp[v][i] + pf[v][i-1]) % mod;
}


int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;


    cin >> n >> D;
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p; p--;
        G[p].push_back(i);
        G[i].push_back(p);
    }
    calc(0, -1);
    pp[0] = 1;
    for(int i = 1; i <= n + 1; i++) pp[i] = pp[i-1] * (D - i) % mod;
    sp[n+2] = 1;
    for(int i = n + 1; i >= 1; i--) sp[i] = sp[i+1] * (D - i) % mod;
    ll res = 0;
    for(int i = 1; i <= n + 1; i++) {
        ll cur = pf[0][i] * pp[i-1] % mod *
                sp[i+1] % mod * facinv[i-1] % mod * facinv[(n + 1) - i] % mod;
        if((n + 1 - i) % 2 == 1) cur = -cur;
        res += cur;
        res %= mod;
    }
    res = (res + mod) % mod;
    cout << res << endl;

}