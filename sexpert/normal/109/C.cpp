#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = pair<int, int>;

const int MAXN = 1e5 + 10;
int rep[MAXN], sz[MAXN];
set<int> lk;

int find(int u) {
    return rep[u] == u ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    rep[v] = u;
    sz[u] += sz[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int len = 1; len <= 9; len++) {
        for(int x = 0; x < (1 << len); x++) {
            int res = 0;
            for(int i = 0; i < len; i++) {
                if(x & (1 << i))
                    res = res * 10 + 4;
                else
                    res = res * 10 + 7;
            }
            lk.insert(res);
        }
    }

    iota(rep, rep + MAXN, 0);
    fill(sz, sz + MAXN, 1);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(lk.count(w))
            continue;
        join(u, v);
    }

    ll ans = (ll)n * (ll)(n - 1) * (ll)(n - 2);
    for(int i = 1; i <= n; i++) {
        ll cnt = sz[find(i)];
        if(cnt > 1) {
            ans -= (cnt - 1) * (ll)(n - 2) * 2LL;
            ans += (cnt - 1) * (cnt - 2);
        }
    }

    cout << ans << '\n';
}