#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

int n;

struct Tree {
    vector <int> t, valt;
    void relax(int v) {
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
    void add_val(int v, int val) {
        t[v] += val;
        valt[v] += val;
    }
    void push(int v) {
        add_val(2 * v, valt[v]);
        add_val(2 * v + 1, valt[v]);
        valt[v] = 0;
    }
    void build(int v, int l, int r, vector <int> &a) {
        if (r - l == 1) {
            t[v] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, a);
        build(2 * v + 1, m, r, a);
        relax(v);
    }
    Tree(vector <int> &a) : t(4 * n, 0), valt(4 * n, 0) {
        build(1, 0, n, a);
    };
    void add_seg(int l, int r, int val, int lt = 0, int rt = n, int v = 1) {
        if (lt >= r || l >= rt) {
            return;
        }
        if (l <= lt && rt <= r) {
            add_val(v, val);
            return;
        }
        int mt = (lt + rt) / 2;
        push(v);
        add_seg(l, r, val, lt, mt, 2 * v);
        add_seg(l, r, val, mt, rt, 2 * v + 1);
        relax(v);
    }
    int get_min(int l, int r, int lt = 0, int rt = n, int v = 1) {
        if (lt >= r || l >= rt) {
            return INF;
        }
        if (l <= lt && rt <= r) {
            return t[v];
        }
        push(v);
        int mt = (lt + rt) / 2;
        int res = min(get_min(l, r, lt, mt, 2 * v), get_min(l, r, mt, rt, 2 * v + 1));
        relax(v);
        return res;
    }
};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Tree t(a);
    vector <vector <int> > op(n), cl(n);
    vector <pair <int, int> > all;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        all.push_back({l, r});
        t.add_seg(l, r + 1, -1);
        op[l].push_back(r);
        cl[r].push_back(l);
    }
    int res = 0, pos = -1;
    for (int i = 0; i < n; i++) {
        for (int x : op[i]) {
            t.add_seg(i, x + 1, 1);
        }
        int maxk = a[i], mink = t.get_min(0, n);
       //cout << i << " " << maxk << " " << mink << "\n";
        if (maxk - mink > res) {
            res = maxk - mink;
            pos = i;
        }
        for (int x : cl[i]) {
            t.add_seg(x, i + 1, -1);
        }
    }
    cout << res << "\n";
    vector <int> ans;
    for (int i = 0; i < m; i++) {
        auto t = all[i];
        if (t.first > pos || t.second < pos) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
}