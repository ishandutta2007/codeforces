#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pll pair<ll, ll>

using namespace std;

const int N = 200500;
const int inf = 1e9 + 50;
const int mod = 998244353;

int n, K, now, S[N];
vector<int> con[N];
vector<pll> vec[N];
map<int, ll> mp[N];

bool cmp(pll u, pll v) {
    return u.se - u.fi > v.se - v.fi;
}

ll dfs(int u, int k) {
    if (k == 0) return 0;
    if (con[u].empty()) return 1ll * S[u] * k;
    if (mp[u].count(k)) return mp[u][k];

    int d = k / con[u].size(), r = k % con[u].size();
    for (int i = 0; i < con[u].size(); i++) {
        int v = con[u][i];
        vec[u][i].fi = dfs(v, d);
    }
    if (r) {
        for (int i = 0; i < con[u].size(); i++) {
            int v = con[u][i];
            vec[u][i].se = dfs(v, d + 1);
        }
    }
    else {
        for (int i = 0; i < con[u].size(); i++) {
            vec[u][i].se = vec[u][i].fi;
        }
    }
    now = u;
    sort(vec[u].begin(), vec[u].end(), cmp);
    ll rlt = 1ll * k * S[u];
    for (int i = 0; i < r; i++) rlt += vec[u][i].se;
    for (int i = r; i < vec[u].size(); i++) rlt += vec[u][i].fi;
    mp[u][k] = rlt;
    return rlt;
}

int main() {

    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d%d", &n, &K);
        for (int i = 1; i <= n; i++) {
            con[i].clear();
            mp[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int p;
            scanf("%d", &p);
            con[p].push_back(i);
        }
        for (int i = 1; i <= n; i++) scanf("%d", &S[i]);
        for (int i = 1; i <= n; i++) {
            vec[i].resize(con[i].size());
        }
        printf("%lld\n", dfs(1, K));
    }

    return 0;
}