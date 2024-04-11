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
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

constexpr int mod = 1e9 + 7;
vector<int> fact, rev, rfact;

void init(int n) {
    ++n;
    fact.assign(n, 1);
    rev.assign(n, 0);
    rfact.assign(n, 1);
    rev[1] = 1;
    for (int i = 2; i < n; ++i) {
        rev[i] = mod - int(1ll * (mod / i) * rev[mod % i] % mod);
        fact[i] = int(1ll * fact[i - 1] * i % mod);
        rfact[i] = int(1ll * rfact[i - 1] * rev[i] % mod);
    }
}

int C(int n, int k) {
    int denom = int(1ll * rfact[n - k] * rfact[k] % mod);
    return int(1ll * fact[n] * denom % mod);
}

using Segment = pair<int, int>;

Segment Intersect(Segment a, Segment b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

int Len(Segment s) {
    return max(s.second - s.first + 1, 0);
}

bool Within(int p, Segment s) {
    return p >= s.first && p <= s.second;
}

int internal_solve(int pos, int neg, int both, int spos, int sneg) {
    if (pos > spos || neg > sneg) return 0;
    assert(spos - pos + sneg - neg == both);
    return C(both, spos - pos);
}

int solve_for_x(int n, int x, int l, int r) {
    const Segment domain = {0, n - 1};
    Segment pos = Intersect({l - x, r - x}, domain);
    Segment neg = Intersect({l + x, r + x}, domain);
    Segment inter = Intersect(pos, neg);
    int both = Len(inter);
    int pos_only = Len(pos) - both, neg_only = Len(neg) - both;
    int neither = n - pos_only - neg_only - both;
    if (neither) {
        return 0;
    }
    if ((n & 1) == 0) {
        return internal_solve(pos_only, neg_only, both, n >> 1, n >> 1);
    }
    int ans =
        internal_solve(pos_only, neg_only, both, n >> 1, (n + 1) >> 1) +
        internal_solve(pos_only, neg_only, both, (n + 1) >> 1, n >> 1);
    if (ans >= mod) ans -= mod;
    return ans;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    --l, --r;
    init(n);
    int l1 = l, r1 = r - n + 1;
    Segment trivial_x = Intersect({l1, r1}, {-r1, -l1});
    int ans = 0;
    if (int ln = Len(trivial_x); ln > 0) {
        if (Within(0, trivial_x)) {
            --ln;
        }
        ans += int(1ll * solve_for_x(n, trivial_x.first, l, r) * ln % mod);
    }
    vector<int> non_trivial_x;
    for (int i = 2 * n - 1; i >= 0; --i) {
        int x = trivial_x.first - i - 1;
        if (x == 0) continue;
        non_trivial_x.pb(x);
    }
    for (int i = 0; i < 2 * n; ++i) {
        int x = trivial_x.second + i + 1;
        if (x == 0) continue;
        non_trivial_x.pb(x);
    }
    for (int i = 0; i + 1 < len(non_trivial_x); ++i) {
        assert(non_trivial_x[i + 1] > non_trivial_x[i]);
    }
    for (auto& x : non_trivial_x) {
        ans += solve_for_x(n, x, l, r);
        if (ans >= mod) ans -= mod;
    }
    int r2 = (mod >> 1) + 1;
    cout << (1ll * ans * r2) % mod << endl;
}