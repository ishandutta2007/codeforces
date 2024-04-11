#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)3e5 + 50;
const ll INF = (ll)1e18;
typedef pair<ll, ll> pll;

struct edge {
    int to, cost;
};

int n, q;
vector<edge> G[N];
int on[N];
ll dep[N];
int sub[N];
ll mxlen = -INF;

ll get_depth(int v, int p) {
    ll res = 0;
    sub[v] = 1;
    for(auto &e : G[v]) {
        if(e.to != p) {
            res = max(res, e.cost + get_depth(e.to, v));
            sub[v] += sub[e.to];
        }
    }
    return res;
}

void dfs(int v, int p, ll d) {
    on[v] = (v == n - 1);
    dep[v] = d;
    for(auto &e : G[v]) {
        if(e.to != p) {
            dfs(e.to, v, d + e.cost);
            on[v] |= on[e.to];
        }
    }
}

pll solve(int v, int p) {
    ll mxup = 0;
    int sbs = 0;
    for(auto &e : G[v]) {
        if(!on[e.to] && e.to != p) {
            mxup = max(mxup, e.cost + get_depth(e.to, v));
            sbs += sub[e.to];
        }
    }
    if(sbs > 1) mxlen = INF;
//    cout << v + 1 << ": dep, " << mxup << endl;
    if(v == n - 1) {
        return {mxup, -INF};
    }
    for(auto &e : G[v]) {
        if(on[e.to] && e.to != p) {
            pll nxt_solve = solve(e.to, v);
            if(nxt_solve.first == 0 && mxup == 0) {
                mxlen = max(mxlen, nxt_solve.second + mxup - e.cost);
            } else {
                mxlen = max(mxlen, max(nxt_solve.second, nxt_solve.first) + mxup - e.cost);
            }
//            cout << v + 1 << " " << mxup << " " << max(nxt_solve.second, nxt_solve.first) << endl;
            return {mxup, max(nxt_solve.second, nxt_solve.first) - e.cost};
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n - 1) {
        int u, v, cost; cin >> u >> v >> cost;
        u--, v--;
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }
    dfs(0, -1, 0);
    solve(0, -1);
    rep(i, 0, q) {
        int l; cin >> l;
        ll olen = dep[n - 1] - dep[0];
        cout << min(olen, olen + l + mxlen) << '\n';
    }
}