#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)4e5 + 50;

struct edge {
    int to, id;
};


int n;
int cnt = 0;
map<pll, int> toid;
vector<edge> G[N];
bool vis[N];
int dep[N];
vector<pii> res;

int get_id(pll p) {
    ll g = __gcd(p.first, p.second);
    p.first /= g, p.second /= g;
    if(!toid.count(p)) toid[p] = cnt++;
    return toid[p];
}

bool dfs(int v, int up_id, int d) {
    vector<int> nxtid;
    if(up_id != -1) nxtid.push_back(up_id);
    vis[v] = true;
    dep[v] = d;
    for(auto e : G[v]) {
        if(e.id == up_id) continue;
        if(vis[e.to]) {
            if(dep[e.to] > dep[v]) nxtid.push_back(e.id);
        }
        else {
            if(dfs(e.to, e.id, d + 1)) nxtid.push_back(e.id);
        }
    }
    while(sz(nxtid) >= 2) {
        int a = nxtid.back(); nxtid.pop_back();
        int b = nxtid.back(); nxtid.pop_back();
        res.push_back({a, b});
    }
    return !nxtid.empty();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int u = get_id({1LL * c * b, 1LL * (a + b) * d});
        int v = get_id({1LL * (c + d) * b, 1LL * a * d});
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    rep(i, 0, cnt) {
        if(!vis[i]) dfs(i, -1, 0);
    }
    cout << sz(res) << '\n';
    for(auto p : res) cout << p.first + 1 << " " << p.second + 1 << '\n';
}