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

void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x : a) {
        cin >> x;
    }
    for (auto& x : b) {
        cin >> x;
    }
    int ita = 0, itb = 0;
    vector<int> res;
    while (ita < n && itb < m) {
        if (a[ita] <= k) {
            if (a[ita] == 0) {
                ++k;
            }
            res.pb(a[ita++]);
        } else if (b[itb] <= k) {
            if (b[itb] == 0) {
                ++k;
            }
            res.pb(b[itb++]);
        } else {
            cout << -1 << endl;
            return;
        }
    }
    while (ita < n) {
        if (a[ita] <= k) {
            if (a[ita] == 0) {
                ++k;
            }
            res.pb(a[ita++]);
        } else {
            cout << -1 << endl;
            return;
        }
    }
    while (itb < m) {
        if (b[itb] <= k) {
            if (b[itb] == 0) {
                ++k;
            }
            res.pb(b[itb++]);
        } else {
            cout << -1 << endl;
            return;
        }
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}