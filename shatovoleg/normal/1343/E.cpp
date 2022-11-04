// #pragma GCC optimize("Ofast,unroll-all-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair
#define int ll

#define debug(x) cout << #x << " = " << x << endl;

const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);

// const int MEM_SIZE = 1e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("squads");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

vector<int> make_bfs(const vector<vector<int>> &g, int s) {
    int n = len(g);
    vector<int> dist(n, INF);
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (len(q)) {
        int v = q.front();
        q.pop();
        for (auto &x : g[v]) {
            if (cmin(dist[x], dist[v] + 1)) {
                q.push(x);
            }
        }
    }

    return dist;
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    --a, --b, --c;
    vector<int> p(m);
    for (auto &x : p) {
        cin >> x;
    }
    p.pb(0);
    sort(all(p));
    for (int i = 0; i < m; ++i) {
        p[i + 1] += p[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> da = make_bfs(g, a), db = make_bfs(g, b), dc = make_bfs(g, c);
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (da[i] + db[i] + dc[i] > m) {
            continue;
        }
        cmin(ans, p[da[i] + db[i] + dc[i]] + p[db[i]]);
    }
    cout << ans << endl;
}

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}