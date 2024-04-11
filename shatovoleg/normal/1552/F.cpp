// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>
#include <unistd.h>

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
    // cin >> n;
    n = 1;
    while (n --> 0) {
        solve();
    }
}

void solve() {
    constexpr int mod = 998'244'353;
    int n;
    cin >> n;
    string s;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        char c;
        cin >> c;
        s.pb(c);
    }
    vector<int> pref_cost(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int c = x[i] - y[i];
        int idx = (int)(lower_bound(all(x), y[i]) - x.begin());
        c += pref_cost[i] - pref_cost[idx];
        while (c >= mod) {
            c -= mod;
        }
        if (c < 0) {
            c += mod;
        }
        if ((c += pref_cost[i]) >= mod) {
            c -= mod;
        }
        pref_cost[i + 1] = c;
    }

    int sm = x.back() + 1;
    if (sm >= mod) {
        sm -= mod;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            sm += pref_cost[i + 1] - pref_cost[i];
            if (sm >= mod) {
                sm -= mod;
            }
            if (sm < 0) {
                sm += mod;
            }
        }
    }
    cout << sm << endl;
}