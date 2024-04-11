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


const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);
const ll INFll = 1e18 + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

// const int MEM_SIZE = 5e8;
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

void solve();

void run() {
    int n = 1;
    // cin >> n;
    while (n --> 0) {
        solve();
    }
}

struct SegTree {
    vector<int> tree, add;
    int n;

    SegTree(int sz) : n(sz) {
        while (n & (n - 1)) ++n;
        tree.resize(2 * n - 1, 0);
        add.resize(2 * n - 1, 0);
    }

    void recalc(int idx) {
        tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void push(int idx, int l, int r) {
        if (add[idx] == 0) return;
        int a = add[idx];
        add[idx] = 0;
        tree[idx] += a;
        if (r - l == 1) return;
        add[2 * idx + 1] += a;
        add[2 * idx + 2] += a;
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return INF;
        push(v, tl, tr);
        if (tl >= l && tr <= r) {
            return tree[v];
        }
        int mid = (tl + tr) >> 1;
        return min(
            query(2 * v + 1, tl, mid, l, r),
            query(2 * v + 2, mid, tr, l, r)
        );
    }

    int query(int l, int r) {
        return query(0, 0, n, l, r);
    }

    void plus(int v, int tl, int tr, int l, int r, int val) {
        push(v, tl, tr);
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            add[v] += val;
            push(v, tl, tr);
            return;
        }
        int mid = (tl + tr) >> 1;
        plus(2 * v + 1, tl, mid, l, r, val);
        plus(2 * v + 2, mid, tr, l, r, val);
        recalc(v);
    }

    void plus(int l, int r, int val) {
        plus(0, 0, n, l, r, val);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> segs(n);
    for (auto& [w, l, r] : segs) {
        cin >> l >> r >> w;
        --l, --r;
    }
    sort(all(segs));
    SegTree t(m - 1);
    int l = 0, r = 0;
    int ans = INF;
    while (l < n) {
        while (r < n && t.query(0, m - 1) == 0) {
            t.plus(segs[r][1], segs[r][2], 1);
            ++r;
        }
        if (t.query(0, m - 1) == 0) break;
        cmin(ans, segs[r - 1][0] - segs[l][0]);
        t.plus(segs[l][1], segs[l][2], -1);
        ++l;
    }
    cout << ans << endl;
}