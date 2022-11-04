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

inline int bpow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res *= a;
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

struct TaskSolver {
    int n;
    vector<int> tree;
    function<int(int, int)> ask;

    TaskSolver(int _n, function<int(int, int)> _ask) : n(_n), ask(_ask) {
        while (n & (n - 1)) ++n;
        tree.resize(2 * n - 1, -1);
    }

    int getVal(int idx, int l, int r) {
        if (tree[idx] == -1) {
            tree[idx] = ask(l, r);
        }
        return tree[idx];
    }

    void update(int idx) {
        idx += n - 1;
        idx = 2 * idx + 1;
        while (idx > 0) {
            idx = (idx - 1) >> 1;
            if (tree[idx] != -1) --tree[idx];
        }
    }

    int query(int v, int tl, int tr, int k) {
        if (tr - tl == 1) return tl;
        int mid = (tl + tr) >> 1;
        if (int lval = getVal(2 * v + 1, tl, mid); lval > k) {
            return query(2 * v + 1, tl, mid, k);
        } else {
            return query(2 * v + 2, mid, tr, k - lval);
        }
    }

    int query(int k) {
        return query(0, 0, n, k);
    }
};

void run() {
    int n, m;
    cin >> n >> m;
    TaskSolver t(n, [n](int l, int r) {
        assert(l < n);
        cmin(r, n);
        cout << "? " << l + 1 << " " << r << endl;
        int val;
        cin >> val;
        return r - l - val;
    });
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        --k;
        int ans = t.query(k);
        cout << "! " << ans + 1 << endl;
        t.update(ans);
    }
}