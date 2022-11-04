// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 1e18l + 666 : 1e9 + 666);
const ll INFll = 1e18 + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

// const int MEM_SIZE = (250 << 20);
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(ll a, ll b, int mod) {
    int res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int((1ll * a * res) % mod);
            res %= mod;
        }
        a *= a;
        a %= mod;
    }
    return res;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("taskname");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

struct SegTree {
    vector<pii> full_cover, part_cover;
    int offset;
    int n;

    SegTree(int sz) : offset(0), n(sz) {
        while (n & (n - 1)) ++n;
        full_cover.resize(2 * n - 1, {0, -1});
        part_cover.resize(2 * n - 1, {0, -1});
    }

    pii query(int l, int r) const {
        pii res = query(0, 0, n, l, r);
        res.first += offset;
        return res;
    }

    void shift(int val) {
        offset += val;
    }

    void add_seg(int l, int r, pii val) {
        val.first -= offset;
        add_seg(0, 0, n, l, r, val);
    }

    void add_seg(int v, int tl, int tr, int l, int r, pii val) {
        if (tl >= r || tr <= l) {
            return;
        }
        if (tl >= l && tr <= r) {
            cmin(full_cover[v], val);
            return;
        }
        cmin(part_cover[v], val);
        int mid = (tl + tr) >> 1;
        add_seg(2 * v + 1, tl, mid, l, r, val);
        add_seg(2 * v + 2, mid, tr, l, r, val);
    }

    pii query(int v, int tl, int tr, int l, int r) const {
        if (tl >= r || tr <= l) {
            return {INF, -2};
        }
        if (tl >= l && tr <= r) {
            return min(full_cover[v], part_cover[v]);
        }
        int mid = (tl + tr) >> 1;
        pii ans = min(
            query(2 * v + 1, tl, mid, l, r),
            query(2 * v + 2, mid, tr, l, r)
        );
        cmin(ans, full_cover[v]);
        return ans;
    }
};

void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> segs(n);
    vector<int> crd;
    crd.reserve(2 * m);
    for (int i = 0; i < m; ++i) {
        int idx, l, r;
        cin >> idx >> l >> r;
        --idx;
        --l;
        segs[idx].pb({l, r});
        crd.pb(l);
        crd.pb(r);
    }
    sort(all(crd));
    crd.resize(unique(all(crd)) - crd.begin());
    for (auto& line : segs) {
        for (auto& [l, r] : line) {
            l = int(lower_bound(all(crd), l) - crd.begin());
            r = int(lower_bound(all(crd), r) - crd.begin());
        }
    }
    vector<int> dp(n), prv(n);
    SegTree t(len(crd));
    for (int i = 0; i < n; ++i) {
        pii cur = {INF, -2};
        for (auto& [l, r] : segs[i]) {
            cmin(cur, t.query(l, r));
        }
        t.shift(1);
        tie(dp[i], prv[i]) = cur;
        for (auto& [l, r] : segs[i]) {
            t.add_seg(l, r, {dp[i], i});
        }
    }
    int mini = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] + n - i < dp[mini] + n - mini) {
            mini = i;
        }
    }
    vector<char> deleted(n, 1);
    while (mini != -1) {
        deleted[mini] = 0;
        mini = prv[mini];
    }
    vector<int> ans;
    for (int i = 0; i < len(deleted); ++i) {
        if (deleted[i]) {
            ans.pb(i);
        }
    }
    cout << len(ans) << endl;
    for (auto& x : ans) {
        cout << x + 1 << " ";
    }
    cout << endl;
}