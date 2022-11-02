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

const int INF = 2e9 + 7;

struct SegmentTree{
    int n;
    vector<int> tree;
    SegmentTree() {}
    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl >= tr) {
            return;
        } else if (tl == tr - 1) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm, a);
            build(v * 2 + 1, tm, tr, a);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    SegmentTree(const vector<int>& a) : n(a.size()), tree(4 * n, 0) {
        build(1, 0, n, a);
    }
    int getMax(int v, int tl, int tr, int l, int r) const {
        if (tl >= r || tr <= l) return -INF;
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return max(getMax(v * 2, tl, tm, l, r), getMax(v * 2 + 1, tm, tr, l, r));
    }
    int getMax(int l, int r) const {
        // return *max_element(tree.begin() + l, tree.begin() + r + 1);
        return getMax(1, 0, n, l, r + 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<SegmentTree> path;
    for (int it = 0; it < 2; ++it) {
        vector<int> cur_path;
        for (int i = 0; i < n; ++i) {
            cur_path.push_back(a[it][i] - i);
        }
        for (int i = 0; i < n; ++i) {
            cur_path.push_back(a[it ^ 1][n - 1 - i] - i - n);
        }
        path.push_back(SegmentTree(cur_path));
    }

    int x = 0, y = 0, cur_time = 0;
    int ans = INF;
    while (y < n) {
        if (x % 2 == 0 && y % 2 == 0) {
            int path_id;
            int l, r;
            path_id = 0;
            l = y + 1;
            r = 2 * n - 1 - y;
            if (l < r) {
                int val = path[path_id].getMax(l, r) + y + 1 - cur_time;
                // cerr << "l = " << l << " r = " << r << " val = " << val << " cur_time = " << cur_time << endl;
                chkmax(val, 0);
                chkmin(ans, cur_time + val + r - l + 1);
            }
        }
        if (x % 2 == 1 && y % 2 == 1) {
            int path_id;
            int l, r;
            path_id = 1;
            l = y + 1;
            r = 2 * n - 1 - y;
            if (l < r) {
                int val = path[path_id].getMax(l, r) + y + 1 - cur_time;
                // cerr << "l = " << l << " r = " << r << " val = " << val << " cur_time = " << cur_time << endl;
                chkmax(val, 0);
                chkmin(ans, cur_time + val + r - l + 1);
            }
        }
        if (x % 2 == 0 && y % 2 == 0) {
            ++x;
        } else if (x % 2 == 1 && y % 2 == 0) {
            ++y;
        } else if (x % 2 == 1 && y % 2 == 1) {
            --x;
        } else if (x % 2 == 0 && y % 2 == 1) {
            ++y;
        }
        if (y < n) {
            ++cur_time;
            chkmax(cur_time, a[x][y] + 1);
        }
    }
    // cerr << "cur_time = " << cur_time << endl;
    chkmin(ans, cur_time);
    cout << ans << '\n';
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