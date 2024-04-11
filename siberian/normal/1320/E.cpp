#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define time time228
#define int ll

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<vector<int>> g;

void read() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

const int MAXN = 2e5 + 10;
const int MAXLOG = 18;

int tin[MAXN], tout[MAXN], h[MAXN], dp[MAXN][MAXLOG];
int timer;

void dfs_lca(int v, int p, int len) {
    tin[v] = timer++;
    h[v] = len++;
    dp[v][0] = p;
    for (int i = 1; i < MAXLOG; i++)
        dp[v][i] = dp[dp[v][i - 1]][i - 1];
    for (auto i : g[v]) {
        if (i != p) {
            dfs_lca(i, v, len);
        }
    }
    tout[v] = timer++;
}

bool is_upper(int v, int u) {
    return tin[v] <= tin [u] && tout[v] >= tout[u];
}

int lca(int v, int u) {
    if (is_upper(v, u)) return v;
    if (is_upper(u, v)) return u;
    for (int i = MAXLOG - 1; i >= 0; i--)
        if (!is_upper(dp[v][i], u))
            v = dp[v][i];
    return dp[v][0];
}

int dist(int v, int u) {
    return h[v] + h[u] - 2 * h[lca(v, u)];
}

void build() {
    timer = 0;
    dfs_lca(0, 0, 0);
}

struct edge{
    int to, cost;
    edge() {}
    edge(int _to, int _cost) {
        to = _to, cost = _cost;
    }
};

struct event{
    int type, speed;
    event() {
        type = -1, speed = 0;
    }
    event(int _type, int _speed) {
        type = _type;
        speed = _speed;
    }
};

struct fdp{
    int type, len;
    fdp() {
        type = -1, len = 0;
    }
    fdp(int _type, int _len) {
        type = _type, len = _len;
    }
};

vector<vector<int>> ans;

void dfs_down(int v, int p, vector<vector<edge>> & g, vector<event> & have, vector<fdp> & dp, vector<int> & s) {
    for (auto [to, cost] : g[v]) {
        if (to == p) continue;
        dfs_down(to, v, g, have, dp, s);
    }
    if (have[v].type != -1) {
        dp[v].type = have[v].type;
        dp[v].len = 0;
    }
    for (auto [to, cost] : g[v]) {
        if (to == p) continue;
        if (dp[to].type == -1) continue;
        int check_time = (dp[to].len + cost + s[dp[to].type] - 1) / s[dp[to].type];
        int have_time = (dp[v].len + s[dp[v].type] - 1) / s[dp[v].type];
        if (dp[v].type == -1 || tie(check_time, dp[to].type) < tie(have_time, dp[v].type)) {
            dp[v].type = dp[to].type;
            dp[v].len = dp[to].len + cost;
        }
    }
}

void dfs_up(int v, int p, vector<vector<edge>> & g, vector<event> & have, vector<fdp> & dp, vector<int> & s) {
    for (auto [to, cost] : g[v]) {
        if (to != p) continue;
        assert(dp[to].type != -1);
        int check_time = (dp[to].len + cost + s[dp[to].type] - 1) / s[dp[to].type];
        int have_time = (dp[v].len + s[dp[v].type] - 1) / s[dp[v].type];
        if (dp[v].type == -1 || tie(check_time, dp[to].type) < tie(have_time, dp[v].type)) {
            dp[v].type = dp[to].type;
            dp[v].len = dp[to].len + cost;
        }
    }
    for (auto [to, cost] : g[v]) {
        if (to == p) continue;
        dfs_up(to, v, g, have, dp, s);
    }
}

vector<int> solve(vector<vector<edge>> g, vector<event> have, vector<int> query, vector<int> s) {
    int n = g.size();
    vector<fdp> dp(n);
    dfs_down(0, 0, g, have, dp, s);
    dfs_up(0, 0, g, have, dp, s);
    vector<int> ans;
    for (auto i : query) {
        ans.push_back(dp[i].type);
    }
    return ans;
}

vector<vector<edge>> build_graph(vector<int> & v, vector<int> & u) {
    vector<int> have;
    for (auto i : v) have.push_back(i);
    for (auto i : u) have.push_back(i);
    sort(all(have), [&] (int a, int b) {return tin[a] < tin[b];});
    have.resize(unique(all(have)) - have.begin());
    int sz = have.size();
    for (int i = 1; i < sz; i++) {
        have.push_back(lca(have[i - 1], have[i]));
    }
    sort(all(have), [&] (int a, int b) {return tin[a] < tin[b];});
    have.resize(unique(all(have)) - have.begin());

    for (auto &i : v) {
        i = lower_bound(all(have), i, [&] (int a, int b) {return tin[a] < tin[b];}) - have.begin();
    }
    for (auto &i : u) {
        i = lower_bound(all(have), i, [&] (int a, int b) {return tin[a] < tin[b];}) - have.begin();
    }

    vector<int> st;
    vector<vector<edge>> g(have.size());
    for (auto i : have) {
        while (!st.empty() && !is_upper(st.back(), i))
            st.pop_back();
        if (!st.empty()) {
            int v = i;
            int u = st.back();
            int d = dist(v, u);
            v = lower_bound(all(have), v, [&] (int a, int b) {return tin[a] < tin[b];}) - have.begin();
            u = lower_bound(all(have), u, [&] (int a, int b) {return tin[a] < tin[b];}) - have.begin();
            g[v].push_back({u, d});
            g[u].push_back({v, d});
        }
        st.push_back(i);
    }
    return g;
}

void solve() {
    int k, m;
    cin >> k >> m;
    vector<int> v(k), s(k), u(m);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        v[i]--;
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> u[i];
        u[i]--;
    }
    vector<vector<edge>> fg = build_graph(v, u);
    vector<event> have(fg.size());
    for (int i = 0; i < k; i++) {
        have[v[i]] = {i, s[i]};
    }
    vector<int> fans = solve(fg, have, u, s);
    ans.push_back(fans);
}

void run() {
    build();
    int q;
    cin >> q;
    while (q--)
        solve();
}

void write() {
    for (auto i : ans) {
        for (auto j : i) {
            cout << j + 1 << " ";
        }
        cout << "\n";
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