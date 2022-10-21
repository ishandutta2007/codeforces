#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1000050, mod = (int)1e9 + 7, N = M;

bool p[M];
int mu[M], pm[M], phi[M], pms;

vector<int> divs[N];
int n, k, q;
ll fac[N], facinv[N];
int cnt[N];
ll F[N], f[N];
ll res = 0;
ll inv[N];

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
}



void get_mobius_and_sieve(){
    mu[1] = 1;
    phi[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                phi[i * pm[j]] = phi[i] * pm[j];
                break;
            }
            mu[i * pm[j]] = -mu[i];
            phi[i * pm[j]] = phi[i] * (pm[j] - 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    get_mobius_and_sieve();
    init_fac();

    cin >> n >> k >> q;
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) divs[j].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        int a; cin >> a; cnt[a]++;
    }
    for(int i = 1; i < N; i++) {
        for(int j : divs[i]) {
            if(i == j) continue;
            cnt[j] += cnt[i];
        }
    }

    for(int i = 1; i < N; i++) {
        res += 1LL * phi[i] * comb(cnt[i], k);
        res %= mod;
    }
    while(q--) {
        int c; cin >> c;
        for(int d : divs[c]) {
            res -= phi[d] * comb(cnt[d], k);
            cnt[d]++;
            res += phi[d] * comb(cnt[d], k);
    }
        res %= mod;
        cout << (res + mod) % mod << '\n';
    }

}