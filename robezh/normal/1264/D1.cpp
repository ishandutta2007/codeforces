#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int N = (int)2000 + 50;

int n, num[N];
ll fac[N], facinv[N];
ll inv[N];
ll Csum[N][N];


ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    if(n < 0 || k < 0 || n - k < 0) return 0;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    for(int i = 0; i < N; i++) Csum[i][0] = comb(i, 0);
    for(int j = 1; j < N; j++) {
        for(int i = 0; i < N; i++) Csum[i][j] = (Csum[i][j-1] + comb(i, j)) % mod;
    }
}


string str;


ll calc(int max_depth) {
    int cntl = 0, cntr = 0, cntq = 0;
    int sl = 0, sr = 0, sq = 0;
    for(char c : str) {
        if(c == '(') sl++;
        else if(c == ')') sr++;
        else sq++;
    }

    ll res = 0;
    for(char c : str) {
        if (c == '(') cntl++, sl--;
        else if (c == ')') cntr++, sr--;
        else cntq++, sq--;

        if(c == ')') continue;
        if(c == '?') {
            if (sr <= max_depth) {
                res += comb(cntq - 1, max_depth - cntl) * Csum[sq][max_depth - sr];
                res %= mod;
            }
        }
        else {
            if (sr <= max_depth) {
                res += comb(cntq, max_depth + 1 - cntl) * Csum[sq][max_depth - sr];
                res %= mod;
            }
        }
    }
    if(cntl <= max_depth) res += Csum[cntq][max_depth - cntl];
    res %= mod;
    return res;
}

ll g[N];

int main() {
    init_fac();
    cin >> str;
    n = str.length();
    for(int i = 0; i <= n; i++) {
        g[i] = calc(i);
//        cout << i << ": " << g[i] << endl;
    }
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        res += i * (g[i] - g[i-1]) % mod;
//        cout << i << ": " << ((g[i] - g[i-1]) % mod + mod) % mod << endl;
        res %= mod;
    }
    cout << (res % mod + mod) % mod << endl;
}