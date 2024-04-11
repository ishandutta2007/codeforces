#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

const int INF = -1e9;

struct SegmentTree{
    int n;
    vector<int> tree;
    SegmentTree() {}
    SegmentTree(int _n) : n(_n), tree(4 * n, INF) {}
    void upd(int v, int tl, int tr, int pos, int val) {
        if (tl >= pos + 1 || tr <= pos) return;
        if (tl == tr - 1) {
            chkmax(tree[v], val);
        } else {
            int tm = (tl + tr) / 2;
            upd(v * 2, tl, tm, pos, val);
            upd(v * 2 + 1, tm, tr, pos, val);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void upd(int pos, int val) {
        // chkmax(tree[pos], val);
        upd(1, 0, n, pos, val);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return INF;
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
    }
    int get(int l, int r) {
        chkmax(l, 0);
        chkmin(r, n - 1);
        if (l > r) return INF;
        // return *max_element(tree.begin() + l, tree.begin() + r + 1);
        return get(1, 0, n, l, r + 1);
    }
};

int n;
vector<int> a;
vector<int> pref, coord;

int getCoord(int val) {
    return lower_bound(all(coord), val) - coord.begin();
}

int sign(int val) {
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

void solve() {
    cin >> n;
    a.resize(n);
    vin(a);
    pref.resize(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = a[i];
        if (i > 0) {
            pref[i] += pref[i - 1];
        }
    }
    coord = pref;
    sort(all(coord));
    coord.resize(unique(all(coord)) - coord.begin());
    int sz = coord.size();
    SegmentTree tree_positive(sz), tree_negative(sz), tree_zero(sz);
    vector<int> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        dp[i] = sign(pref[i]) * (i + 1);
        int pos = getCoord(pref[i]);
        chkmax(dp[i], tree_positive.get(0, pos - 1) + i);
        chkmax(dp[i], tree_zero.get(pos, pos));
        chkmax(dp[i], tree_negative.get(pos + 1, sz - 1) - i);
        tree_positive.upd(pos, dp[i] - i);
        tree_negative.upd(pos, dp[i] + i);
        tree_zero.upd(pos, dp[i]);
        // for (int j = 0; j < i; ++j) {
        //     chkmax(dp[i], dp[j] + (i - j) * sign(pref[i] - pref[j]));
        // }
    }
    // cerr << "dp = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << dp[i] << " ";
    // }
    // cerr << endl;
    cout << dp[n - 1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}