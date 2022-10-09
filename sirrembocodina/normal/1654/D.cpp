#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int mod = 998244353;
vector<int> cnt;
vector<int> mn;
vector<vector<pair<int, pair<int, int>>>> g;
vector<pair<int, int>> f[200001];
int inv[200001];

int bin_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = bin_pow(a, b / 2);
    (res *= res) %= mod;
    if (b % 2) {
        (res *= a) %= mod;
    }
    return res;
}

void dfs1(int v, int p) {
    for (auto e: g[v]) {
        int to = e.first, b = e.second.first, c = e.second.second;
        if (to == p) {
            continue;
        }
        for (auto x: f[c]) {
            cnt[x.first] += x.second;
        }
        for (auto x: f[b]) {
            cnt[x.first] -= x.second;
            mn[x.first] = min(mn[x.first], cnt[x.first]);
        }
        dfs1(to, v);
        for (auto x: f[c]) {
            cnt[x.first] -= x.second;
        }
        for (auto x: f[b]) {
            cnt[x.first] += x.second;
        }
    }
}

int ans = 0;

void dfs2(int v, int p, int x) {
    (ans += x) %= mod;
    for (auto e: g[v]) {
        int to = e.first, b = e.second.first, c = e.second.second;
        if (to == p) {
            continue;
        }
        dfs2(to, v, x * c % mod * inv[b] % mod);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    for (int n = 1; n <= 200000; n++) {
        int cur = n;
        for (int i = 2; i * i <= cur; i++) {
            if (cur % i) continue;
            int cnt = 0;
            while (cur % i == 0) {
                cur /= i;
                cnt++;
            }
            f[n].push_back({i, cnt});
        }
        if (cur > 1) {
            f[n].push_back({cur, 1});
        }
    }
    for (int n = 1; n <= 200000; n++) {
        inv[n] = bin_pow(n, mod - 2);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.clear();
        g.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            a--; b--;
            g[a].push_back({b, {x, y}});
            g[b].push_back({a, {y, x}});
        }
        cnt.clear();
        cnt.resize(n + 1);
        mn.clear();
        mn.resize(n + 1);
        dfs1(0, -1);
        int x = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < -mn[i]; j++) {
                (x *= i) %= mod;
            }
        }
        ans = 0;
        dfs2(0, -1, x);
        cout << ans << '\n';
    }
    return 0;
}