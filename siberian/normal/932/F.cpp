#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int INF = 1e18, MAXN = 1e5 + 10;

struct line{
    int k, b;
    line() {
        k = 0, b = INF;
    }
    line(int x, int y) {
        k = x, b = y;
    }
};

int eval(line l, int x) {
    return l.k * x + l.b;
}

struct node{
    node * l, * r;
    line x;
    node() {
        x = {};
        l = nullptr;
        r = nullptr;
    }
    node(line new_x) {
        x = new_x;
        l = nullptr;
        r = nullptr;
    }
};

const int MAXC = 1e5;

struct cht{
    node * root;
    vector<line> l;

    cht() {
        root = new node();
        l = {};
    }

    node * add(line x, node * tree, int tl = -MAXC, int tr = MAXC + 1) {
        if (tree == nullptr) tree = new node();
        int tm = (tl + tr) / 2;
        bool left = eval(tree->x, tl) > eval(x, tl);
        bool mid = eval(tree->x, tm) > eval(x, tm);
        if (mid) swap(x, tree->x);
        if (tl == tr - 1) return tree;
        if (left != mid) {
            tree->l = add(x, tree->l, tl, tm);
        }
        else {
            tree->r = add(x, tree->r, tm, tr);
        }
        return tree;
    }

    void add(line x) {
        root = add(x, root);
        l.push_back(x);
    }

    int get(node * tree, int tl, int tr, int pos) {
        if (tree == nullptr) return INF;
        if (tl >= pos + 1 || tr <= pos) return INF;
        if (tl == tr - 1) return eval(tree->x, pos);
        int tm = (tl + tr) / 2;
        return min(eval(tree->x, pos), min(get(tree->l, tl, tm, pos), get(tree->r, tm, tr, pos)));
    }

    int get(int x) {
        return get(root, -MAXC, MAXC + 1, x);
    }
};


int n;
int a[MAXN], b[MAXN], ans[MAXN], sz[MAXN];
vector<int> g[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void merge(cht & a, cht & b) {
    for (auto i : b.l)
        a.add(i);
}

void dfs_sz(int v, int p) {
    sz[v] = 1;
    for (auto i : g[v]) {
        if (i != p) {
            dfs_sz(i, v);
            sz[v] += sz[i];
        }
    }
}

cht dfs(int v) {
    ans[v] = INF;
    if (g[v].empty()) {
        ans[v] = 0;
        cht help;
        help.add(line(b[v], ans[v]));
        return help;
    }

    cht help;
    bool flag = false;
    for (auto i : g[v]) {
        if (!flag) {
            help = dfs(i);
            flag = true;
        } else {
            auto x = dfs(i);
            merge(help, x);
        }
    }

    ans[v] = help.get(a[v]);
    help.add(line(b[v], ans[v]));
    return help;
}

void run() {
    dfs_sz(0, -1);
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), [&] (int a, int b) {return sz[a] > sz[b];});
        if (i > 0) {
            g[i].erase(g[i].begin());
        }
    }
    dfs(0);
}

void write() {
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}