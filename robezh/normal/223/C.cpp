#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2005;
const ll mod = (ll)1e9 + 7;

int n, k, num[N];
ll fac[N], facinv[N];
ll inv[N];
ll fack[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll res[N];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> num[i];

    if(k == 0) {
        for(int i = 0; i < n; i++) cout << num[i] << " ";
        return 0;
    }
    k--;
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    fack[0] = 1;
    for(int i = 1; i < N - 1; i++) fack[i] = fack[i-1] * (k + i) % mod;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            res[i] += fack[i-j] * facinv[i-j] % mod * num[j];
            res[i] %= mod;
        }
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";
}