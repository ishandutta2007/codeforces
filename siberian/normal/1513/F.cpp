#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

const int N = 2e5 + 10;
int n;
int a[N], b[N], ordA[N], ordB[N];

struct SegmentTree{
    vector<int> tree;
    int n;
    SegmentTree() {}
    SegmentTree(int _n) {
        n = _n;
        tree.assign(4 * n, (int)2e9 + 228);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return (int)2e9 + 228;
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return min(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
    }
    int get(int l, int r) {
        return get(1, 0, n, l, r + 1);
        // return *min_element(tree.begin() + l, tree.begin() + r + 1);
    }
    void upd(int v, int tl, int tr, int pos, int val) {
        if (tl >= pos + 1 || tr <= pos) return;
        if (tl == tr - 1) {
            chkmin(tree[v], val);
            return;
        }
        int tm = (tl + tr) / 2;
        upd(v * 2, tl, tm, pos, val);
        upd(v * 2 + 1, tm, tr, pos, val);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
    void upd(int pos, int val) {
        upd(1, 0, n, pos, val);
        // chkmin(tree[pos], val);
    }
};

struct DataStructure{
    // vector<int> treeLess, treeBigger;
    SegmentTree treeLess, treeBigger;
    vector<int> coord;
    DataStructure() {
        for (int i = 0; i < n; ++i) {
            coord.push_back(a[i]);
        }
        sort(all(coord));
        coord.resize(unique(all(coord)) - coord.begin());
        // treeLess.assign(coord.size(), (int)2e9 + 228);
        // treeBigger.assign(coord.size(), (int)2e9 + 228);
        treeLess = SegmentTree(coord.size());
        treeBigger = SegmentTree(coord.size());
    }
    void add(int a, int b, int val) {
        int pos = lower_bound(all(coord), a) - coord.begin();
        // chkmin(treeLess[pos], - abs(a - b) + val - a);
        // chkmin(treeBigger[pos], - abs(a - b) + val + a);
        treeLess.upd(pos, -abs(a - b) + val - a);
        treeBigger.upd(pos, -abs(a - b) + val + a);
    }
    int getTreeLess(int l, int r) {
        // return *min_element(treeLess.begin() + l, treeLess.begin() + r + 1);
        return treeLess.get(l, r);
    }
    int getTreeBigger(int l, int r) {
        // return *min_element(treeBigger.begin() + l, treeBigger.begin() + r + 1);
        return treeBigger.get(l, r);
    }
    ll get(int bi) {
        int pos = lower_bound(all(coord), bi) - coord.begin();
        int ans = 2e9 + 228;
        if (pos > 0) {
            chkmin(ans, bi + getTreeLess(0, pos - 1));
        }
        if (pos < coord.size()) {
            chkmin(ans, getTreeBigger(pos, coord.size() - 1) - bi);
        }
        return ans;
    }
};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    iota(ordA, ordA + n, 0);
    sort(ordA, ordA + n, [&] (int i, int j) {
        return a[i] < a[j];
    });
    iota(ordB, ordB + n, 0);
    sort(ordB, ordB + n, [&] (int i, int j) {
        return b[i] < b[j];
    });
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - b[i]);
    }
    // cerr << "oldAns = " << ans << endl;
    ll oldAns = ans;
    int posB = 0;
    DataStructure solver;
    for (int posA = 0; posA < n; ++posA) {
        while (posB < n && b[ordB[posB]] <= a[ordA[posA]]) {
            solver.add(a[ordB[posB]], b[ordB[posB]], -b[ordB[posB]]);
            ++posB;
        }
        ll myAns = oldAns - abs(a[ordA[posA]] - b[ordA[posA]]) + solver.get(b[ordA[posA]]) + a[ordA[posA]];
        chkmin(ans, myAns);
    }
    solver = DataStructure();
    posB = n - 1;
    for (int posA = n - 1; posA >= 0; --posA) {
        while (posB >= 0 && b[ordB[posB]] >= a[ordA[posA]]) {
            solver.add(a[ordB[posB]], b[ordB[posB]], b[ordB[posB]]);
            // cerr << "add " << a[ordB[posB]] << " " << b[ordB[posB]] << endl;
            --posB;
        }
        ll myAns = oldAns - abs(a[ordA[posA]] - b[ordA[posA]]) + solver.get(b[ordA[posA]]) - a[ordA[posA]];
        // cerr << "posA = " << posA << " myAns = " << myAns << endl;
        chkmin(ans, myAns);
    }
    cout << ans << endl;
    return 0;
}