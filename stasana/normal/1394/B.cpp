#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

const ll MOD1 = 2286661337;
const ll MOD2 = 1'000'000'009;

ll power(ll x, ll n, ll mod) {
    if (n == 0) {
        return 1;
    }
    if (n & 1) {
        return (x * power(x * x % mod, n >> 1, mod)) % mod;
    }
    return power(x * x % mod, n >> 1, mod);
}

struct Hash {
    ll x;
    ll y;

    Hash() {
        x = 0;
        y = 0;
    }

    Hash(ll z) {
        x = power(47, z, MOD1);
        x = power(179, z, MOD2);
    }

    Hash operator +(Hash other) {
        Hash res;
        res.x = (x + other.x) % MOD1;
        res.y = (y + other.y) % MOD2;
        return res;
    }

    Hash operator -(Hash other) {
        Hash res;
        res.x = (x - other.x + MOD1) % MOD1;
        res.y = (y - other.y + MOD2) % MOD2;
        return res;
    }

    bool operator ==(Hash other) {
        return x == other.x && y == other.y;
    }
};

vector<vector<Hash>> hs;
Hash need_hash;
ll result = 0;

void f(Hash x, ll k) {
    if (k == hs.size()) {
        if (need_hash == x) {
            ++result;
        }
        return;
    }
    for (ll i = 0; i <= k; ++i) {
        f(x + hs[k][i], k + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    hs.resize(k);
    for (ll i = 0; i < k; ++i) {
        hs[i].resize(i + 1);
    }
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll v, u, w;
        cin >> v >> u >> w;
        g[v - 1].emplace_back(w, u - 1);
    }
    for (ll i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
        need_hash = need_hash + Hash(i);
    }
    for (ll v = 0; v < n; ++v) {
        for (ll i = 0; i < g[v].size(); ++i) {
            hs[(ll)g[v].size() - 1][i] = hs[(ll)g[v].size() - 1][i] + Hash(g[v][i].second);
        }
    }

    f(Hash(), 0);

    cout << result << endl;

    return 0;
}