#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;
using II = array<ll, 2>;

map<II, int> v_idx;
map<ii, int> e_idx;
const int MAXN = 4e5 + 10;
vector<ii> adj[MAXN];
vector<ii> ops;
set<int> taken;
int vi[MAXN];

II reduce(ll x, ll y) {
    ll g = __gcd(x, y);
    x /= g;
    y /= g;
    return {x, y};
}

void dfs(int s, int p = 0) {
    vi[s] = 1;
    vector<ii> nei;
    ii pedge;
    for(auto e : adj[s]) {
        if(e[0] == p) {
            pedge = e;
            continue;
        }
        if(vi[e[0]])
            continue;
        dfs(e[0], s);
    }

    for(auto e : adj[s]) {
        if(e[0] == p)
            continue;
        if(!taken.count(e[1]))
            nei.push_back(e);
    }
    
    if(nei.size() % 2 && p != 0)
        nei.push_back(pedge);

    for(int i = 0; i + 1 < nei.size(); i += 2) {
        int u = nei[i][1], v = nei[i + 1][1];
        ops.push_back({u, v});
        taken.insert(u);
        taken.insert(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int vts = 0, n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        II r = reduce(b * c, (a + b) * d);
        if(!v_idx.count(r))
            v_idx[r] = ++vts;
        II s = reduce(b * (c + d), a * d);
        if(!v_idx.count(s))
            v_idx[s] = ++vts;
        int u = v_idx[r], v = v_idx[s];
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for(int i = 1; i <= vts; i++)
        if(!vi[i])
            dfs(i);

    cout << ops.size() << '\n';
    for(auto &[x, y] : ops)
        cout << x << " " << y << '\n';
}