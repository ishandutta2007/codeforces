#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 1e6 + 10, M = 1e6, Q = 1e6;
int n, m, q;
int p[N];
pair<int, int> e[M];

int type[Q], query[Q];

void read() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> e[i].first >> e[i].second;
        e[i].first--;
        e[i].second--;
    }
    for (int i = 0; i < q; ++i) {
        cin >> type[i] >> query[i];
        query[i]--;
    }
}

int par[N + M];

int getPar(int v) {
    if (v == par[v]) return v;
    return par[v] = getPar(par[v]);
}

void uni(int a, int b) {
    assert(a != b);
    assert(a == getPar(a));
    //cout << a << " " << getPar(a) << endl;
    //cout << b << " " << getPar(b) << endl;
    assert(b == getPar(b));
    par[a] = b;
}

void init() {
    iota(par, par + n + m, 0);
}

vector<int> g[N + M];
int topG;

void add(int u, int v) {
    //cout << "add: u = " << u << " v = " << v << endl;
    u = getPar(u);
    v = getPar(v);
    if (u == v) return;
    int root = topG++;
    //cout << "root = " << root << endl;
    g[root].push_back(u);
    g[root].push_back(v);
    uni(u, root);
    uni(v, root);
}

bool used[M];

int tin[N], tout[N], timer = 0;

void dfs(int v) {
    used[v] = true;
    tin[v] = timer++;
    for (auto i : g[v]) {
        if (used[i]) continue;
        dfs(i);
    }
    tout[v] = timer - 1;
}


struct Node{
    int pos, val;
    Node() {
        pos = -1, val = -1;
    }
    Node(int _pos, int _val) {
        pos = _pos, val = _val;
    }
};

Node merge(const Node& a, const Node& b) {
    if (a.val < b.val) {
        return b;
    } else {
        return a;
    }
}

struct SegmentTree{
    int n;
    vector<Node> tree;
    vector<int> pos;
    SegmentTree() {}

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            //cout << "tl = " << tl << " a[tl] = " << a[tl] << endl;
            tree[v] = Node(tl, a[tl]);
            pos[tl] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm, tr, a);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.assign(4 * n, Node());
        pos.assign(n, 0);
        build(1, 0, n, a);
        /*
        for (int i = 0; i < n; ++i) {
            tree[i] = Node(i, a[i]);
        }*/
    }

    Node get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return Node();
        if (tl >= l && tr <= r) 
            return tree[v];
        int tm = (tl + tr) / 2;
        return merge(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
    }

    Node get(int l, int r) {
        assert(l >= 0 && r < n);
        return get(1, 0, n, l, r + 1);
        /*
        Node ans;
        for (int i = l; i <= r; ++i) {
            ans = merge(ans, tree[i]);
        }
        return ans;*/
    }
    void clear(int v) {
        assert(v != -1);
        assert(v >= 0 && v < n);
        tree[pos[v]] = Node(v, 0);
        v = pos[v] / 2;
        while (v) {
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
            v /= 2;
        }
    }
};

int myRoot[Q];
SegmentTree tree;

void build() {
    init();
    for (int i = 0; i < q; ++i) {
        if (type[i] == 2) {
            used[query[i]] = true;
        }
    }
    /*cout << "used = " << endl;
    for (int i = 0; i < m; ++i) {
        cout << used[i] << " ";
    }
    cout << endl;*/
    topG = n;
    for (int i = 0; i < m; ++i) {
        if (!used[i]) {
            add(e[i].first, e[i].second);
        }
    }
    for (int i = q - 1; i >= 0; --i) {
        if (type[i] == 1) {
            myRoot[i] = getPar(query[i]);
        } else if (type[i] == 2) {
            add(e[query[i]].first, e[query[i]].second);
        }
    }
    //cout << "topG = " << topG << endl;
    //assert(n + m == topG);
    fill(used, used + n + m, false);
    for (int i = topG - 1; i >= 0; --i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    vector<int> a(n + m, -1);
    for (int i = 0; i < n; ++i) {
        a[tin[i]] = p[i];
    }
    tree = SegmentTree(a);
}

int topAns;
int ans[Q];

void solve() {
    topAns = 0;
    for (int i = 0; i < q; ++i) {
        if (type[i] == 1) {
            auto have = tree.get(tin[myRoot[i]], tout[myRoot[i]]);
            //cout << "have = ";
            //cout << have.pos << " " << have.val << endl;
            ans[topAns++] = have.val;
            tree.clear(have.pos);
        }
    }
}

void run() {
    build();
    solve();
}

void write() {
    for (int i = 0; i < topAns; ++i) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}