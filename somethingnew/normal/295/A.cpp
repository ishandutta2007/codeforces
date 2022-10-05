#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define INF 1e9
#define int long long
int sizee;
struct segment_tree {
    int sz = 0;
    vector<int> def, tree;

    void upd(int v) {
        if (v < sz) {
            tree[v] = max(tree[v * 2] + def[v * 2], tree[v * 2 + 1] + def[v * 2 + 1]);
        }
    }

    segment_tree(int n, vector<int> a) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        sizee = sz;
        tree.assign(sz * 2, -INF);
        def.assign(sz * 2, 0);
        for (int i = 0; i < n; i++) {
            tree[sz + i] = a[i];
        }
        for (int i = sz - 1; i > 0; --i) {
            upd(i);
        }
    }

    void push(int v) {
        if (v < sz) {
            def[v * 2] += def[v];
            def[v * 2 + 1] += def[v];
        } else {
            tree[v] += def[v];
        }
        def[v] = 0;
    }

    void add(int l, int r, int x, int v = 1, int tl = 0, int tr = sizee - 1) {
        if (r < tl || l > tr) {
            return;
        }
        if (l <= tl && tr <= r) {
            def[v] += x;
            push(v);
            upd(v);
            return;
        }
        push(v);
        upd(v);
        int tm = (tl + tr) / 2;
        add(l, r, x, v * 2, tl, tm);
        add(l, r, x, v * 2 + 1, tm + 1, tr);
        push(v);
        upd(v);
    }

    int get(int l, int r, int v = 1, int tl = 0, int tr = sizee - 1) {
        if (r < tl || l > tr) {
            return -INF;
        }
        push(v);
        upd(v);
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        auto ans = max(get(l, r,v * 2, tl, tm), get(l, r, v * 2 + 1, tm + 1, tr));
        push(v);
        upd(v);
        return ans;
    }
};
signed main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(m, 0);
    segment_tree sg(m, b);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, pair<int, int>>> c(m);
    for (auto &[q, qq] : c)
        cin >> qq.first >> qq.second >> q;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        //cout << x << ' ' << y << endl;
        sg.add(x, y, 1);
    }
    vector<int> ch(n + 1);
    int ind = -1;
    for (auto [q, qq] : c) {
        ind++;
        qq.first--;
        int val = q * sg.get(ind, ind);
        ch[qq.first] += val;
        ch[qq.second] -= val;
    }
    int s = 0;
    for (int j = 0; j < n; ++j) {
        s += ch[j];
        cout << s + a[j] << ' ';
    }
}