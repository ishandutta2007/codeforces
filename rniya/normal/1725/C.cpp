#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

ll g1[500001];
ll g2[500001];
ll inverse[500001];

void init() {
    g1[0] = 1, g2[0] = 1;
    g1[1] = 1, g2[1] = 1, inverse[1] = 1;
    for (int i = 2; i <= 500000; i++) {
        g1[i] = (g1[i - 1] * i) % MOD;
        inverse[i] = ((-MOD / i) * inverse[MOD % i]) % MOD;
        if (inverse[i] < 0) {
            inverse[i] += MOD;
        }
        g2[i] = (g2[i - 1] * inverse[i]) % MOD;
    }
}

ll comb(int n, int r) {
    if (r < 0 || n < r) {
        return 0;
    }
    return g1[n] * ((g2[n - r] * g2[r]) % MOD) % MOD;
}

ll modpow(ll n, ll r) {
    n %= MOD;
    ll res = 1;
    while (r) {
        if (r & 1) {
            res = (res * n) % MOD;
        }
        n = (n * n) % MOD;
        r >>= 1;
    }
    return res;
}

typedef long long ll;

int main() {
    init();

    int N, M;
    cin >> N >> M;
    vector<ll> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    vector<ll> cum(N + 1, 0);
    map<ll, int> cum_to_idx;
    for (int i = 0; i < N; i++) {
        cum[i + 1] = cum[i] + D[i];
        if (i < N - 1) {
            cum_to_idx[cum[i + 1]] = i + 1;
        }
    }

    ll S = cum[N];

    int diagonal = 0;
    for (int i = 0; i < N; i++) {
        if (S & 1) {
            continue;
        }
        ll tmp = cum[i] + S / 2;
        if (cum_to_idx.count(tmp)) {
            int j = cum_to_idx[tmp];
            // cout << i << " " << j << endl;
            diagonal++;
        }
    }

    // cout << diagonal << endl;

    ll res = 0;
    for (int k = 0; k <= diagonal; k++) {
        ll tmp = (comb(diagonal, k) * comb(M, k)) % MOD;
        tmp = (tmp * g1[k]) % MOD;
        tmp = (tmp * modpow(M - k, N - 2 * diagonal)) % MOD;
        tmp =
            (tmp * modpow(((M - k) * 1LL * (M - k - 1)) % MOD, diagonal - k)) %
            MOD;
        // cout << tmp << endl;
        res = (res + tmp) % MOD;
    }

    cout << res << endl;
}