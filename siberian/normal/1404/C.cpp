#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

struct Query{
    int r, ind;
};

const int N = 3e5 + 10;
int n, q;
vector<Query> have[N];
vector<int> a;
vector<int> myVal[N];
bool used[N];

void read() {
    cin >> n >> q;
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    for (int i = 0; i < n; i++) {
        myVal[a[i]].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int l = x;
        int r = n - y - 1;
        have[l].push_back({r, i});
    }
}

struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    void upd(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
}; 

const int INF = 1e9 + 10;

struct SegmentTree{
    int n;
    vector<pair<int, int>> tree;
    vector<int> mod;
    SegmentTree() {}

    void build(int v, int tl, int tr, const vector<int> & a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = {a[tl], tl};
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm, tr, a);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }

    SegmentTree(const vector<int> & a) {
        n = a.size();
        tree.assign(n * 4, {INF, INF});
        mod.assign(n * 4, 0);
        build(1, 0, n, a);
    }

    void push(int v) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
        mod[v] = 0;
    }

    pair<int, int> getVal(int v) {
        return make_pair(tree[v].first + mod[v], tree[v].second);
    }

    void del(int v, int tl, int tr, int pos) {
        if (tl >= pos + 1 || tr <= pos) return;
        if (tl == tr - 1) {
            tree[v] = {INF, INF};
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        del(v * 2, tl, tm, pos);
        del(v * 2 + 1, tm, tr, pos);
        tree[v] = min(getVal(v * 2), getVal(v * 2 + 1));
    }

    void del(int pos) {
        del(1, 0, n, pos);
        //tree[pos] = INF;
    }

    void add(int v, int tl, int tr, int l, int r, int val) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            mod[v] += val;
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        add(v * 2, tl, tm, l, r, val);
        add(v * 2 + 1, tm, tr, l, r, val);
        tree[v] = min(getVal(v * 2), getVal(v * 2 + 1)); 
    }

    void add(int l, int val) {
        add(1, 0, n, l, n, val);
        //for (int i = l; i < n; i++) {
        //    tree[i] += val;
        //}
    }
    pair<int, int> get() {
        return getVal(1);
        //int pos = min_element(all(tree)) - tree.begin();
        //return {pos, tree[pos]};
    }
};

Fenwick fans;
SegmentTree tree;

void build() {
    vector<int> delta(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > i || i - a[i] > now) {
            delta[i] = INF;
        } else {
            delta[i] = now - (i - a[i]);
            now++;
        }
    }
    /*cerr << "delta = " << endl;
    for (auto i : delta) {
        cerr << i << " ";
    }
    cerr << endl;*/
    fans = Fenwick(n);
    for (int i = 0; i < n; i++) {
        if (delta[i] != INF) {
            fans.upd(i, 1);
        } else {
            used[i] = true;
        }
    }
    tree = SegmentTree(delta);
}

void Del(int pos) {
    //cerr << "Del = " << pos << endl;
    if (used[pos]) return;
    tree.del(pos);
    tree.add(pos, -1);
    fans.upd(pos, -1);
    used[pos] = true;
}

void del(int pos) {
    for (auto i : myVal[pos]) {
        Del(i);
    }
    Del(pos);
    while (true) {
        auto [val, pos] = tree.get();
        if (val >= 0) break;
        Del(pos);
    }
}

int get(int l, int r) {
    return fans.get(l, r);
}

int ans[N];

void run() {
    build();
    for (int l = 0; l < n; l++) {
        for (auto [r, ind] : have[l]) {
            ans[ind] = get(l, r);
        }
        del(l);
    }
}

void write() {
    for (int i = 0; i < q; i++) {
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