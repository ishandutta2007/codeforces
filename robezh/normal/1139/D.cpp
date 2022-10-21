#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 100050, mod = (int)1e9 + 7;

int m;
bool p[M];
int mu[M], pm[M], pms;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll inv(ll x) {
    return fp(x, mod - 2);
}

void get_mobius_and_sieve(){
    mu[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

int main(){
    get_mobius_and_sieve();

    cin >> m;
    ll res = 1;
    for(int i = 2; i <= m; i++) {
        ll d = m / i;
        res -= mu[i] * d % mod * inv(m - d) % mod;
        res %= mod;
    }
    cout << (res % mod + mod) % mod << endl;
}