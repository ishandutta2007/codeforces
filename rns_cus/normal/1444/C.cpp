#include <bits/stdc++.h>
using namespace std;

#define N 500100

int n, m, k, c[N], nxt[N];
vector <int> adj[N], nei[N];
int dep[N];
bool bad[N];

int rt[N], col[N], sz[N];

typedef pair <int, int> pii;

pii find_rt(int u) {
    int c = 0;
    while (rt[u] != u) {
        c ^= col[u];
        u = rt[u];
    }
    return pii(u, c);
}

vector <pii> all;

bool link(int u, int v) {
    pii pu = find_rt(u), pv = find_rt(v);
    u = pu.first, v = pv.first;
    int c = pu.second ^ pv.second ^ 1;
    if (sz[u] < sz[v]) swap(u, v);
    if (u == v) {
        if (c) return false;
        else return true;
    }
    rt[v] = u, col[v] = c;
    all.emplace_back(u, v);
    sz[u] += sz[v];
    return true;
}

map <pii, vector <pii> > mp;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) scanf("%d", &c[i]), sz[i] = 1, rt[i] = i, col[i] = 0;
    while (m --) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (c[u] == c[v]) {
            if (!bad[c[u]] && !link(u, v)) bad[c[u]] = 1;
            continue;
        }

        if (c[u] > c[v]) swap(u, v);
        mp[pii(c[u],c[v])].emplace_back(u, v);

    }

    long long ans = 1ll * k * (k - 1) / 2, tot = 0;
    int cnt = 0;
    for (int i = 1; i <= k; i ++) {
        if (bad[i]) cnt ++;
    }
    ans -= 1ll * cnt * (k - cnt);
    ans -= 1ll * cnt * (cnt - 1) / 2;

    for (auto &it : mp) {
        if (bad[it.first.first] || bad[it.first.second]) continue;
        vector <pii> &vec = it.second;
        all.clear();
        bool fg = true;
        for (auto p : vec) {
            int u = p.first, v = p.second;
            if (!link(u, v)) {
                fg = false;
                break;
            }
        }
        while (!all.empty()) {
            int u, v;
            tie(u, v) = all.back(); all.pop_back();
            rt[v] = v, sz[u] -= sz[v];
        }
        if (!fg) ans --;
    }


    printf("%I64d\n", ans);


    return 0;
}