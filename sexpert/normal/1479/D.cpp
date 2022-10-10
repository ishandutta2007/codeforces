#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
const int SQRT = 800;
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], ord[2 * MAXN], n, q, a[MAXN], up[MAXN][19], curt, sta[MAXN], bl[SQRT], ans[MAXN];
int L, R;

struct qry {
    int id, ql, qr, l, r;
    bool operator<(const qry &o) const {
        return make_pair(abs(ql)/SQRT, (1 - 2*(abs(ql)/SQRT % 2)) * abs(qr)) < make_pair(abs(o.ql)/SQRT, (1 - 2*(abs(o.ql)/SQRT % 2)) * abs(o.qr));
    }
};
vector<qry> qs;

int lca(int u, int v) {
    if(tin[u] <= tin[v] && tin[v] <= tout[u])
        return u;
    for(int l = 18; l >= 0; l--) {
        int ca = up[u][l];
        if(tin[ca] <= tin[v] && tin[v] <= tout[ca])
            continue;
        u = ca;
    }
    return up[u][0];
}

void dfs(int s, int p = 1) {
    up[s][0] = p;
    tin[s] = ++curt;
    ord[curt] = s;
    for(auto v : adj[s])
        if(v != p)
            dfs(v, s);
    tout[s] = ++curt;
    ord[curt] = s;
}

void upd(int x) {
    int p = a[ord[x]];
    bl[p/SQRT] -= sta[p];
    sta[p] ^= 1;
    bl[p/SQRT] += sta[p];
}

void solve() {
    sort(qs.begin(), qs.end());
    L = 1, R = 0;
    for(auto &q : qs) {
        while(R < abs(q.qr))
            upd(++R);
        while(R > abs(q.qr))
            upd(R--);
        while(L < abs(q.ql))
            upd(L++);
        while(L > abs(q.ql))
            upd(--L);

        //cout << "query " << q.id << " " << abs(q.ql) << " " << abs(q.qr) << " " << L << " " << R << " " << q.l << " " << q.r << " " << '\n';
        //for(int c = 0; c <= 2; c++)
        //    cout << sta[c] << " ";
        //cout << '\n';

        ans[q.id] = -1;
        int u = ord[abs(q.ql)], v = ord[abs(q.qr)], w = -1;
        if(q.ql < 0)
            w = lca(u, v);
        if(w != -1)
            upd(tin[w]);
        for(int b = 0; b < SQRT; b++) {
            if(ans[q.id] != -1)
                break;
            if(b * SQRT + SQRT - 1 >= q.l && b * SQRT <= q.r && bl[b]) {
                for(int i = b * SQRT; i < b * SQRT + SQRT; i++) {
                    if(i < q.l || i > q.r)
                        continue;
                    if(sta[i] == 1) {
                        ans[q.id] = i + 1;
                        break;
                    }
                }
            }
        }
        if(w != -1)
            upd(tin[w]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    //for(int i = 1; i <= n; i++)
    //    cout << i << " " << tin[i] << " " << tout[i] << '\n';

    //for(int i = 1; i <= 2*n; i++)
    //    cout << ord[i] << " ";
    //cout << '\n';

    for(int l = 0; l + 1 < 19; l++)
        for(int i = 1; i <= n; i++)
            up[i][l + 1] = up[up[i][l]][l];

    for(int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        l--;
        r--;
        int w = lca(u, v);
        if(w == u) {
            qs.push_back({i, tin[u], tin[v], l, r});
            continue;
        }
        if(w == v) {
            qs.push_back({i, tin[v], tin[u], l, r});
            continue;
        }
        if(tin[u] > tin[v])
            swap(u, v);
        qs.push_back({i, -tout[u], -tin[v], l, r});
    }

    //for(auto &q : qs)
    //    cout << q.id << " " << q.ql << " " << q.qr << '\n';

    solve();
    for(int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}