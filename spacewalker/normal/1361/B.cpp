#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

ll modexp(ll b, ll e) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

ll modnonexp(ll b, ll e) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b, e / 2);
}

ll solve() {
    ll n, p; scanf("%lld %lld", &n, &p);
    vector<ll> arr(n); for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    if (p == 1) {
        return n % 2;  // lol edge case go brr
    }
    sort(arr.rbegin(), arr.rend());
    int cpow = -1;
    ll cdiff = 0;
    bool bailOut = false;
    for (int v : arr) {
        if (cpow == -1) {
            ++cdiff;
            cpow = v;
            continue;
        } else if (bailOut) {
            cdiff = (cdiff * modexp(p, cpow - v)) % MOD;
            cdiff = (cdiff + MOD - 1) % MOD;
            cpow = v;
        } else {
            if (cdiff > 0) {
                int powerDiff = cpow - v;
                if (powerDiff * log(p) >= 12 || log(cdiff) + powerDiff * log(p) >= 12) {
                    bailOut = true;
                }
                if (bailOut) {
                    cdiff = (cdiff * modexp(p, powerDiff)) % MOD;
                } else {
                    cdiff *= modnonexp(p, powerDiff);
                }
            }
            cpow = v;
            if (bailOut) cdiff = (cdiff + MOD - 1) % MOD;
            else {
                if (cdiff > 0) --cdiff;
                else ++cdiff;
            }
        }
    }
    if (cpow > 0) {
        // multiply cdiff by p ^ cpow
        cdiff = (cdiff * modexp(p, cpow)) % MOD;
    }
    return cdiff % MOD;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%lld\n", solve());
    }
}