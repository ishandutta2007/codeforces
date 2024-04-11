#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, mod = (int)1e9 + 7;

int n,m,q;
int l[N], r[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll ginv(ll x) {
    return fp(x, mod - 2);
}

ll leninv(int i) {
    return ginv(r[i] - l[i] + 1);
}

ll nei[N];
ll ssum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> r[i];
    ll res = 1;
    for(int i = n - 2; i >= 0; i--) {
        int ml = max(l[i], l[i+1]), mr = min(r[i], r[i+1]);
        int len = max(0, mr - ml + 1);
        nei[i] = len * leninv(i) % mod * leninv(i+1) % mod;
        nei[i] = (1 - nei[i]) % mod;
        ssum[i] = (ssum[i+1] + nei[i]) % mod;
        res += 3 * nei[i] % mod;
    }
//    res += 3 * ssum[0] % mod;
    for(int i = 0; i < n - 3; i++) {
        res += 2 * nei[i] % mod * ssum[i+2] % mod;
    }
    res %= mod;
    for(int i = 0; i < n - 2; i++) {
        int ml = max(max(l[i], l[i+1]), l[i+2]), mr = min(min(r[i], r[i+1]), r[i+2]);
        int len = max(0, mr - ml + 1);
        ll add = 1 - (1 - nei[i]) - (1 - nei[i+1]) + len * leninv(i) % mod * leninv(i+1) % mod * leninv(i+2) % mod;
        res += add * 2 % mod;
        res %= mod;
    }
    cout << (res % mod + mod) % mod << endl;
}