#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, m, p;

struct el{
    int val, cost;
    el() {}
    el(int _val, int _cost) {
        val = _val, cost = _cost;
    }
};

bool operator<(const el & a, const el & b) {
    return tie(a.val, a.cost) < tie(b.val, b.cost);
}

struct event{
    int x, y, val;
    event() {}
};

bool operator<(const event & a, const event & b) {
    return a.x < b.x;
}

vector<el> a, b;
vector<event> have;

void read() {
    cin >> n >> m >> p;
    a.resize(n);
    for(auto &i : a) {
        cin >> i.val >> i.cost;
    }
    b.resize(m);
    for (auto &i : b) {
        cin >> i.val >> i.cost;
    }
    sort(all(a));
    sort(all(b));
    have.resize(p);
    for (auto &i : have) {
        cin >> i.x >> i.y >> i.val;
    }
    sort(all(have));
}

const int INF = -1e18;

struct segment_tree{
    vector<int> tree;
    vector<int> mod;
    int n;

    segment_tree() {}

    void build(int v, int tl, int tr, const vector<int> & a) {
        if (tl == tr - 1) {
            tree[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm, tr, a);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }

    segment_tree(vector<int> a) {
        n = a.size();
        //tree = a;
        tree.assign(n * 4, INF);
        mod.assign(n * 4, 0);
        build(1, 0, n, a);
    }

    void push(int v) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
        tree[v] += mod[v];
        mod[v] = 0;
    }

    int get_val(int v) {
        return tree[v] + mod[v];
    }

    void upd(int v, int tl, int tr, int l, int r, int add) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            mod[v] += add;
            return;
        } 
        push(v);
        int tm = (tl + tr) / 2;
        upd(v * 2, tl, tm, l, r, add);
        upd(v * 2 + 1, tm, tr, l, r, add);
        tree[v] = max(get_val(v * 2), get_val(v * 2 + 1));
    }

    int get() {
        return get_val(1);
        int ans = INF;
        for (auto i : tree)
            chkmax(ans, i);
        return ans;
    }

    void upd(int r, int val) {
        upd(1, 0, n, r, n, val);
        //for (int i = r; i < n; i++)
        //    tree[i] += val;
    }
};

int ans;

void run() {
    /*cout << "a = " << endl;
    for (auto i : a) {
        cout << i.val << " " << i.cost << endl;
    }

    cout << "b = " << endl;
    for (auto i : b) {
        cout << i.val << " " << i.cost << endl;
    }

    cout << "have = " << endl;
    for (auto i : have) {
        cout << i.x << " " << i.y << " " << i.val << endl;
    }*/

    ans = INF;
    int pos = 0;
    vector<int> fcost;
    for (auto i : b)
        fcost.push_back(-i.cost);
    segment_tree tree(fcost);
    for (auto i : a) {
        while (pos < (int)have.size() && have[pos].x < i.val) {
            int cnt = (lower_bound(all(b), el(have[pos].y + 1, INF))) - b.begin();
            tree.upd(cnt, have[pos].val);
            pos++;
        }
       /* cout << "pos = " << pos << endl;
        cout << "tree = " << endl;
        for (auto j : tree.tree)
        cout << j << " ";
        cout << endl;*/
        chkmax(ans, tree.get() - i.cost);
    }
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}