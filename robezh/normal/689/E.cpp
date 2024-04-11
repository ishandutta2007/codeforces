#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)2e5 + 50;
const ll mod = (ll)1e9 + 7;

int n, num[N], k;
P p[2 * N];
ll fac[N], facinv[N];
ll inv[N];
ll cpsum[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}


int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> p[2 * i].first; p[2 * i].second = 1;
        cin >> p[2 * i + 1].first; p[2 * i + 1].first ++;
        p[2 * i + 1].second = -1;
    }
    n *= 2;
    sort(p, p + n);
    ll res = 0;
    int cur = 0;
    for(int i = 0, r = 0; i < n; ) {
        while(r < n && p[r].first == p[i].first) {
            cur += p[r].second;
            r++;
        }
        if(r >= n) break;
        ll len = p[r].first - p[i].first;
        if(cur >= k) res += len * comb(cur, k), res %= mod;
        i = r;
    }
    cout << (res % mod + mod) % mod << endl;

}