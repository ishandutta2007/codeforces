#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 1005, mod = (int)1e9 + 7, N = M;

int m, n, k;
int gp[M], ngp[M];
int sz[M];
ll sp[N];

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
int main() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sp[1] = 1;
    for(int i = 2; i < N; i++) {
        sp[i] = 1;
        for(int j = 0; j < i; j++) {
            sp[i] = (sp[i] + comb(i - 1, j) * sp[i - 1 - j]) % mod;
        }
    }

    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        k = 0;
        for(int j = 0; j < m; j++) {
            int cat = -1;
            for(int l = 0; l < j; l++) {
                if(gp[j] == gp[l] && str[j] == str[l]) cat = ngp[l];
            }
            if(cat == -1) cat = k++;
            ngp[j] = cat;
        }
        for(int j = 0; j < m; j++) gp[j] = ngp[j];
    }
    ll res = 1;
    for(int i = 0; i < m; i++) sz[gp[i]]++;
    for(int i = 0; i < k; i++) res = (res * sp[sz[i]]) % mod;
    cout << (res % mod + mod) % mod << endl;
}