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

const int INF = -1e18;

struct Item{
    int x, p;
};

struct SegmentTree{
    int n;
    vector<int> tree;
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
    SegmentTree(vector<int> a) {
        n = a.size();
        // tree = a;
        tree.resize(n * 4);
        build(1, 0, n, a);
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
        if (l > r) {
            return INF;
        }
        return get(1, 0, n, l, r + 1);
        // return *max_element(tree.begin() + l, tree.begin() + r + 1);
    }
};

int n, m;
vector<Item> a;

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (auto& [x, p] : a) {
        cin >> x >> p;
    }
    vector<int> coord;
    for (auto i : a) {
        coord.push_back(i.x);
    }
    sort(all(coord));
    coord.resize(unique(all(coord)) - coord.begin());
    auto getCoord = [&] (int x) -> int {
        return lower_bound(all(coord), x) - coord.begin();
    };
    vector<int> val(coord.size());
    {
        vector<int> add_x(coord.size(), 0);
        vector<int> add_y(coord.size(), 0);
        for (auto [x, p] : a) {
            int pos;
            pos = getCoord(x - p);
            add_x[pos] += p - abs(x - coord[pos]);
            add_y[pos] += 1;

            pos = getCoord(x);
            add_y[pos] -= 2;

            pos = getCoord(x + p + 1);
            if (pos < (int)coord.size()) {
                add_y[pos] += 1;
                add_x[pos] -= p - abs(x - coord[pos]);
            }
        }

        int cur_x = 0, cur_y = 0;
        for (int i = 0; i < (int)coord.size(); ++i) {
            if (i > 0) {
                cur_x += (coord[i] - coord[i - 1]) * cur_y;
            }
            cur_x += add_x[i];
            cur_y += add_y[i];
            val[i] = cur_x;
            // cerr << "i = " << i << " cur_x = " << cur_x << " cur_y = " << cur_y << endl;
        }
    }
    // cerr << "val = " << endl;
    // for (auto i : val) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    vector<int> left = val;
    vector<int> right = val;
    for (int i = 0; i < (int)coord.size(); ++i) {
        left[i] -= coord[i];
        right[i] += coord[i];
    }
    SegmentTree full(val);
    SegmentTree l(left);
    SegmentTree r(right);
    for (auto [x, p] : a) {
        int pos = getCoord(x);
        int L = getCoord(x - p);
        int R = getCoord(x + p + 1) - 1;
        int ans = 1;
        if (max(full.get(0, L - 1), full.get(R + 1, coord.size() - 1)) > m) {
            ans = 0;
        } else if (l.get(L, pos) - p + x > m) {
            ans = 0;
        } else if (r.get(pos, R) - p - x > m) {
            ans = 0;
        }
        cout << ans;
    }
    cout << '\n';
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