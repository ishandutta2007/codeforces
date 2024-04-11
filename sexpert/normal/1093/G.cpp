#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const int INF = 1e9;

struct node {
    int l, r;
    int vmax, vmin;
    node(int l = 0, int r = 0, int vmax = -INF, int vmin = INF) : l(l), r(r), vmax(vmax), vmin(vmin){}
};

struct point {
    int coords[5];
    point(vector<int> v = {0, 0, 0, 0, 0}) {
        for(int i = 0; i < 5; i++)
            coords[i] = v[i];
    }
};

struct SegTree {
    int mask;
    vector<node> tree;
    vector<int> pos;

    SegTree(int n, int msk, vector<point> &v) {
        mask = msk;
        tree.resize(4*n);
        pos.resize(n + 1);
        build(1, n, v);
    }

    int oper(point p) {
        int x = mask;
        int result = 0;
        for(int i = 0; i < 5; i++, x /= 2) {
            result += (2*(x%2) - 1)*p.coords[i];
        }
        return result;
    }

    void build(int l, int r, vector<point> &v, int id = 1) {
        tree[id] = node(l, r);
        if(l == r) {
            pos[l] = id;
            tree[id].vmin = tree[id].vmax = oper(v[l]);
        }
        else {
            int m = (l + r)/2;
            build(l, m, v, 2*id);
            build(m + 1, r, v, 2*id + 1);
            tree[id].vmin = min(tree[2*id].vmin, tree[2*id + 1].vmin);
            tree[id].vmax = max(tree[2*id].vmax, tree[2*id + 1].vmax);
        }
    }

    void update(int lf, point val) {
        int id = pos[lf];
        tree[id].vmin = tree[id].vmax = oper(val);
        while(id > 0) {
            id /= 2;
            tree[id].vmin = min(tree[2*id].vmin, tree[2*id + 1].vmin);
            tree[id].vmax = max(tree[2*id].vmax, tree[2*id + 1].vmax);
        }
    }

    int qrymin(int l, int r, int id = 1) {
        node n = tree[id];
        if(n.r < l || n.l > r)
            return INF;
        if(l <= n.l && n.r <= r)
            return n.vmin;
        return min(qrymin(l, r, 2*id), qrymin(l, r, 2*id + 1));
    }

    int qrymax(int l, int r, int id = 1) {
        node n = tree[id];
        if(n.r < l || n.l > r)
            return -INF;
        if(l <= n.l && n.r <= r)
            return n.vmax;
        return max(qrymax(l, r, 2*id), qrymax(l, r, 2*id + 1));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<point> v(n + 1);
    for(int i = 1; i <= n; i++) {
        vector<int> tmp;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        while(tmp.size() < 5)
            tmp.push_back(0);
        v[i] = point(tmp);
    }
    vector<SegTree> trees;
    for(int i = 0; i < (1 << k); i++) {
        trees.push_back(SegTree(n, i, v));
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i;
            cin >> i;
            vector<int> tmp;
            for(int j = 0; j < k; j++) {
                int x;
                cin >> x;
                tmp.push_back(x);
            }
            while(tmp.size() < 5)
                tmp.push_back(0);
            point p = point(tmp);
            for(int t = 0; t < (1 << k); t++) {
                trees[t].update(i, p);
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            int mx = -INF;
            for(int t = 0; t < (1 << k); t++) {
                mx = max(mx, trees[t].qrymax(l, r) - trees[t].qrymin(l, r));
            }
            cout << mx << endl;
        }
    }
}