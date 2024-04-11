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

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct SegmentTree{
    int n;
    vector<ll> tree;

    void build(int v, int tl, int tr, const vector<ll>& a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm, tr, a);
        tree[v] = gcd(tree[v * 2], tree[v * 2 + 1]);
    }

    SegmentTree(const vector<ll>& a) {
        n = a.size();
        tree.assign(n * 4, 0);
        build(1, 0, n, a);
        // tree = a;
    }

    ll get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return 0;
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return gcd(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
    }

    ll get(int l, int r) {
        return get(1, 0, n, l, r + 1);
        // ll ans = 0;
        // for (int i = l; i <= r; ++i) {
        //     ans = gcd(ans, tree[i]);
        // }
        // return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<ll> diff(n);
    for (int i = 0; i + 1 < n; ++i) {
        diff[i] = abs(a[i] - a[i + 1]);
    }
    // cerr << "diff = " << endl;
    // for (auto i : diff) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    SegmentTree tree(diff);
    int r = 0;
    int ans = 1;
    for (int l = 0; l + 1 < n; ++l) {
        chkmax(r, l);
        while (r + 1 < n && tree.get(l, r) > 1) ++r;
        // cerr << l << " " << r << endl;
        chkmax(ans, r - l + 1);
    }
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