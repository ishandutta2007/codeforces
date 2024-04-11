#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 1e6 + 5;
int id[MAXN], rep[MAXN], le[MAXN], ri[MAXN], val[MAXN], del[MAXN], tin[MAXN], tout[MAXN], n, m, q, curt;
vector<int> adj[MAXN];
vector<ii> edgeor;
ii edges[MAXN];
int sz;
set<int> roots;

struct node {
    int l, r;
    ii info;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        if(l == r)
            info = {0, l};
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
            info = max(left->info, right->info);
        }
    }

    void upd(int p, int v) {
        if(r < p || p < l)
            return;
        if(l == r) {
            info = {v, l};
            return;
        }
        left->upd(p, v);
        right->upd(p, v);
        info = max(left->info, right->info);
    }

    ii qry(int rl, int rr) {
        if(rr < l || r < rl)
            return {-1, -1};
        if(rl <= l && r <= rr)
            return info;
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int find(int u) {
    return u == rep[u] ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return;
    int id = ++sz;
    //cout << "parent of " << u << " and " << v << " has id " << id << endl;
    rep[u] = id;
    rep[v] = id;
    roots.erase(u);
    roots.erase(v);
    roots.insert(id);
    adj[id].push_back(u);
    adj[id].push_back(v);
}

void dfs(int s, node& tree) {
    tin[s] = ++curt;
    if(s <= n)
        tree.upd(tin[s], s);
    for(auto v : adj[s])
        dfs(v, tree);
    tout[s] = curt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++)
        cin >> val[i];

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u = val[u];
        v = val[v];
        edges[i] = {u, v};
    }

    vector<ii> qs;
    for(int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;

        if(t == 1)
            qs.push_back({t, val[x]});
        if(t == 2) {
            qs.push_back({t, x});
            del[x] = 1;
        }
    }
    for(int i = 1; i <= m; i++) {
        if(!del[i])
            qs.push_back({2, i});
    }
    vector<int> qids;

    iota(rep, rep + MAXN, 0);

    for(int i = 1; i <= n; i++)
        roots.insert(i);

    sz = n;

    reverse(qs.begin(), qs.end());
    //cout << "QUERIES" << endl;
    for(auto &[t, x] : qs) {
        //cout << t << " " << x << endl;
        if(t == 2) {
            //cout << "adding edge " << edges[x][0] << " " << edges[x][1] << endl;
            join(edges[x][0], edges[x][1]);
            continue;
        }
        int id = find(x);
        //cout << x << " has id " << id << endl;
        qids.push_back(id);
    }

    //for(auto id : qids)
    //    cout << id << " ";
    //cout << '\n';

    curt = 0;

    node tree(1, sz);

    for(auto r : roots)
        dfs(r, tree);

    //for(int i = 1; i <= sz; i++) {
    //    cout << i << " [" << tin[i] << " " << tout[i] << "]" << endl;
    //}

    reverse(qids.begin(), qids.end());

    for(auto id : qids) {
        //cout << "querying " << id << '\n';
        auto info = tree.qry(tin[id], tout[id]);
        //cout << "got " << info[0] << " " << info[1] << '\n';
        cout << info[0] << '\n';
        tree.upd(info[1], 0);
    }
}