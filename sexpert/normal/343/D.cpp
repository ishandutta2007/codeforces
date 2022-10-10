#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r, sum, lazy;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        sum = 0;
        lazy = -1;
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    inline void merge() {
        sum = left->get() + right->get();
    }

    inline void compose(int s) {
        if(s != -1)
            lazy = s;
    }

    inline void push() {
        left->compose(lazy);
        right->compose(lazy);
        lazy = -1;
    }

    int get() {
        if(lazy != -1)
            return (r - l + 1) * lazy;
        return sum;
    }

    void upd(int rl, int rr, int val) {
        if(r < rl || rr < l)
            return;
        if(rl <= l && r <= rr) {
            compose(val);
            return;
        }
        push();
        left->upd(rl, rr, val);
        right->upd(rl, rr, val);
        merge();
    }

    int qry(int rl, int rr) {
        //cout << rl << " " << rr << " " << l << " " << r << " " << lazy << " " << get() << endl;
        if(r < rl || rr < l)
            return 0;
        if(rl <= l && r <= rr)
            return get();
        push();
        merge();
        return left->qry(rl, rr) + right->qry(rl, rr);
    }
};

const int MAXN = 5e5 + 5;
int tree[MAXN], par[MAXN], pos[MAXN], ct = 1;
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    tree[s] = 1;
    par[s] = p;
    pos[s] = ct++;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        tree[s] += tree[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    node st = node(1, n);
    int q;
    cin >> q;
    while(q--) {
        int t, v;
        cin >> t >> v;
        if(t == 2) {
            //cout << pos[v] << " set to 0\n";
            st.upd(pos[v], pos[v], 0);
        }
        if(t == 3) {
            int s = st.qry(pos[v], pos[v] + tree[v] - 1);
            //cout << pos[v] << " " << pos[v] + tree[v] - 1 << " " << s << endl;
            if(s < tree[v])
                cout << "0\n";
            else
                cout << "1\n";
        }
        if(t == 1) {
            int s = st.qry(pos[v], pos[v] + tree[v] - 1);
            if(s < tree[v] && v > 1)
                st.upd(pos[par[v]], pos[par[v]], 0);
            st.upd(pos[v], pos[v] + tree[v] - 1, 1);
        }
    }
}