#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
struct edge{
    int to, id;
    edge() {}
    edge(int _to, int _id) {
        to = _to, id = _id;
    }
};

const int MAXN = 1e5 + 10;
int n;
vector<edge> g[MAXN];
int len[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b >> len[i];
        a--;
        b--;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
}

ld fans;
ll cnt[MAXN];

int sz[MAXN];

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto [to, id] : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        cnt[id] = (ll)sz[to] * (n - sz[to]) * (n - sz[to] - 1) + (ll)sz[to] * (sz[to] - 1) * (n - sz[to]);
    }
}

void build() {
    dfs(0, 0);
    for (int i = 0; i < n - 1; i++) {
        fans += (ld)cnt[i] / ((ll)n * (n - 1) * (n - 2) / 6) * len[i];
    }
}

void upd(int id, int val) {
    fans -= (ld)cnt[id] / ((ll)n * (n - 1) * (n - 2) / 6) * len[id];
    len[id] = val;
    fans += (ld)cnt[id] / ((ll)n * (n - 1) * (n - 2) / 6) * len[id];
}

ld get() {
    return fans;
}

vector<ld> ans;

void run() {
    build();
    int q;
    cin >> q;
    while (q--) {
        int id, val;
        cin >> id >> val;
        id--;
        upd(id, val);
        ans.push_back(get());
    }
}

void write() {
    cout.precision(10);
    cout.setf(ios::fixed);
    for (auto i : ans) {
        cout << i << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}