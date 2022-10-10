#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXF = 2e5 + 5;
const int MAXN = 3e3 + 5;
const ll MOD = 1e9 + 7;
vector<pair<int, ll>> adj[MAXN];
ll paths[MAXN], fact[MAXF], h, w;
int n, vist[MAXN];
pair<int, int> loc[MAXN];

ll mpow(ll b, ll e) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b * mpow(b, e - 1)) % MOD;
    ll p = mpow(b, e/2);
    return (p * p) % MOD;
}

ll inv(ll b) {
    return mpow(b, MOD - 2);
}

ll binom(int n, int k) {
    return (fact[n] * inv((fact[k] * fact[n - k]) % MOD)) % MOD;
}

ll dfs(int s) {
    vist[s] = 1;
    for(auto e : adj[s]) {
        int v = e.first;
        ll w = e.second;
        if(!vist[v])
            dfs(v);
        paths[s] = (MOD + paths[s] + (paths[v] * w + MOD) % MOD) % MOD;
    }
    return paths[s];
}

int main() {
    fact[0] = 1;
    for(ll i = 1; i < MAXF; i++)
        fact[i] = (i * fact[i - 1]) % MOD;
    cin >> h >> w >> n;
    for(int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;
        loc[i] = {r, c};
    }
    loc[0] = {1, 1}, loc[n + 1] = {h, w};
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= n + 1; j++) {
            int dh = loc[j].first - loc[i].first, dv = loc[j].second - loc[i].second;
            if(dh < 0 || dv < 0)
                continue;
            if(i == j)
                continue;
            adj[i].push_back({j, -binom(dh + dv, dh)});
        }
    }
    paths[n + 1] = -1;
    cout << (dfs(0) + MOD) % MOD << endl;
}