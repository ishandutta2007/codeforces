#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
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
    // UseFiles("shelves");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

vector<vector<int>> g;
vector<int> beauty;

vector<pii> compress(vector<pii> v) {
    // sort(all(v));
    vector<pii> ans;
    for (auto &[x, y] : v) {
        if (!len(ans) || ans.back().first != x) {
            ans.pb({x, 0});
        }
        ans.back().second += y;
    }
    return ans;
}

const int mod = 1e9 + 7;
int ans = 0;

void dfs(int v, int p, const vector<pii> &_g) {
    vector<pii> G(_g);
    for (auto &[x, y] : G) {
        x = __gcd(x, beauty[v]);
    }
    G.pb({beauty[v], 1});
    G = compress(G);
    for (auto &[x, y] : G) {
        ans += x * y;
        ans %= mod;
    }
    for (auto &x : g[v]) {
        if (x == p) {
            continue;
        }
        dfs(x, v, G);
    }
}

void run() {
    int n;
    cin >> n;
    g.resize(n);
    beauty.resize(n);
    for (auto &x : beauty) {
        cin >> x;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, -1, vector<pii>());
    cout << ans % mod << endl;
}