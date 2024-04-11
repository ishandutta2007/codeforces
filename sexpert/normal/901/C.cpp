#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 3e5 + 10;
ll ans[MAXN];
int vis[MAXN], in[MAXN], worst[MAXN];
vector<int> adj[MAXN], idx[MAXN], path;
vector<ii> bad, qs[MAXN];

struct BIT {
    ll b[MAXN];
    BIT() {
        fill(b, b + MAXN, 0);
    }

    void upd(int p, ll v) {
        for(; p < MAXN; p += (p & -p)) b[p] += v;
    }

    ll sum(int p) {
        ll res = 0;
        for(; p; p -= (p & -p))
            res += b[p];
        return res;
    }

    ll qry(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
BIT wo, cn;

void dfs(int s, int p = 0) {
    vis[s] = 1;
    in[s] = 1;
    path.push_back(s);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        if(!vis[v])
            dfs(v, s);
        else if(in[v]){
            int u, mi = MAXN, ma = -MAXN;
            do {
                u = path.back(); path.pop_back();
                in[u] = 0;
                ma = max(ma, u);
                mi = min(mi, u);
            } while(u != v);
            worst[ma] = max(worst[ma], mi);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int u = 1; u <= n; u++)
        if(!vis[u]) dfs(u);
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        worst[i] = max(worst[i], cur);
        cur = worst[i];
        wo.upd(i, worst[i]);
        idx[cur].push_back(i);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qs[l].push_back({r, i});
    }
    for(int l = 1; l <= n; l++) {
        for(auto i : idx[l - 1]) {
            wo.upd(i, -worst[i]);
            cn.upd(i, 1);
        }
        for(auto p : qs[l]) {
            int r = p.first;
            ll d = r - l + 1;
            ll tot = (ll)r*(r + 1)/2 - (ll)l*(l - 1)/2;
            tot -= wo.qry(l, r);
            tot -= cn.qry(l, r) * (l - 1);
            ans[p.second] = tot;
        }
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}