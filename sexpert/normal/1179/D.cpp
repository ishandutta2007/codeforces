#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 10;
const ll INF = 1e18;
ll sz[MAXN], dp[MAXN], ans = INF, n;
vector<int> adj[MAXN];

struct line {
    ll m, b;
    ll eval(ll x) { return m*x + b; }
    ll isect(line o) { return (long double)(b - o.b)/(o.m - m); }
};

struct cht {
    deque<line> hull;
    ll query(ll x) {
        assert(hull.size());
        while(hull.size() >= 2 && hull[1].eval(x) >= hull[0].eval(x)) hull.pop_front();
        return hull[0].eval(x);
    }
    void add_line(ll m, ll b) {
        line to_add = {m, b};
        if(hull.size() && hull[0].m == m) {
            if(b > hull[0].b)
                hull.pop_front();
            else
                return;
        }
        while(hull.size() >= 2 && hull[0].isect(to_add) > hull[0].isect(hull[1])) hull.pop_front();
        hull.push_front(to_add);
    }
};

void calc(int s, int p = 0) {
    sz[s] = 1;
    for(auto v : adj[s]) {
        if(v == p) continue;
        calc(v, s);
        sz[s] += sz[v];
    }
    dp[s] = INF;
    if(adj[s].size() == 1)
        dp[s] = sz[s]*sz[s];
    for(auto v : adj[s]) {
        if(v == p) continue;
        dp[s] = min(dp[s], (sz[s] - sz[v])*(sz[s] - sz[v]) + dp[v]);
    }
}

void solve(int s, int p = 0) {
    for(auto v : adj[s]) {
        if(v == p) continue;
        solve(v, s);
    }
    sort(adj[s].begin(), adj[s].end(), [&](int a, int b){ return sz[a] < sz[b]; });
    cht helper;
    for(int i = 0; i < adj[s].size(); i++) {
        if(adj[s][i] == p) continue;
        int v = adj[s][i];
        if(helper.hull.size())
            ans = min(ans, n*n + sz[v]*sz[v] - 2LL*n*sz[v] + dp[v] - helper.query(sz[v]));
        helper.add_line(-2LL*sz[v], 2LL*sz[v]*n - sz[v]*sz[v] - dp[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int rt;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n == 2) {
        cout << "2\n";
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() > 1) {
            rt = i;
            break;
        }
    }
    //cout << rt << endl;
    calc(rt);
    //for(int i = 1; i <= n; i++)
    //    cout << i << " " << sz[i] << endl;
    solve(rt);
    cout << n*(n - 1) - (ans - n)/2 << '\n';
}