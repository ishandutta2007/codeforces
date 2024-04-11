#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

int n, m;
int dep[N];
vi G[N];
vector<pii> up[N];
map<int, ll> mp[N];
int idx[N];
ll sub[N];
ll off[N];

void insert_new(int v, pll p) {
    auto it = mp[v].upper_bound(p.first);
    if(it != mp[v].begin()) {
        it--;
        if(it->second + off[v] <= p.second) return ;
    }
    it = mp[v].lower_bound(p.first);
    while(it != mp[v].end()) {
        if(it -> second + off[v] >= p.second) it = mp[v].erase(it);
        else break;
    }
    mp[v][p.first] = p.second - off[v];
}

int unite(int u, int v) {
    if(sz(mp[u]) > sz(mp[v])) swap(u, v);
    for (auto &p : mp[u]) {
        insert_new(v, {p.first, p.second + off[u]});
    }
    return v;
}

void dfs(int v, int p, int d) {
    dep[v] = d;
    ll tot = 0;
    idx[v] = v;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v, d + 1);
        while(!mp[idx[nxt]].empty() && mp[idx[nxt]].rbegin() -> first > d) {
            mp[idx[nxt]].erase(prev(mp[idx[nxt]].end()));
        }
        if(mp[idx[nxt]].empty()) {
            cout << -1 << endl;
            exit(0);
        }
        sub[nxt] = mp[idx[nxt]].rbegin()->second + off[idx[nxt]];
        tot += sub[nxt];
    }
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        off[idx[nxt]] += tot - sub[nxt];
        idx[v] = unite(idx[v], idx[nxt]);
    }
    for (auto &u : up[v]) {
        insert_new(idx[v], {dep[u.first], u.second + tot});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    rep(i, 0, m) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        if(u != v) up[u].push_back({v, c});
    }
    dfs(0, -1, 0);
    auto it = mp[idx[0]].find(0);
    if(it == mp[idx[0]].end()) {
        return cout << -1 << endl, 0;
    } else {
        cout << it->second + off[idx[0]] << '\n';
    }
}