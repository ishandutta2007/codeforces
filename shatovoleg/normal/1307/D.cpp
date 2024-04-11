#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pii pair<int, int>
#define pb push_back
#define kek pop_back
#define mp make_pair
// #define int ll

const int INF = (is_same<int, ll>::value ? 1e18L + 666 : 1e9L + 666);

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

vector<int> make_bfs(const vector<vector<int>> &g, int s) {
    int n = len(g);
    vector<int> dist(n, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
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

void run() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> fld(k);
    for (auto &x : fld) {
        cin >> x;
        --x;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dist_fr = make_bfs(g, 0), dist_to = make_bfs(g, n - 1);
    vector<pii> d;
    for (auto &x : fld) {
        d.pb({dist_fr[x], dist_to[x]});
    }
    sort(all(d), [](const pii &a, const pii &b) {
        if (a.first != b.first) {
            return a < b;
        }
        return a > b;
    });
    int ans = 0;
    int cur_mx = d.back().second;
    for (int i = k - 2; i > -1; --i) {
        cmax(ans, d[i].first + cur_mx + 1);
        cmax(cur_mx, d[i].second);
    }
    cmin(ans, dist_fr[n - 1]);
    cout << ans << endl;
}