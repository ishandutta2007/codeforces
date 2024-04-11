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

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a == b) {
        cout << min(x, y) / a << endl;
        return;
    }
    if (a < b) {
        swap(a, b);
        swap(x, y);
    }
    ll n = x * a - y * b, m = a * y - b * x;
    if (n < 0 || m < 0) {
        if (m < 0) {
            swap(a, b);
            swap(x, y);
        }
        cout << x / min(a, b) << endl;
        return;
    }
    n /= a * a - b * b;
    m /= a * a - b * b;
    ll ans = n + m;
    if ((n + 1) * a + m * b <= x && (n + 1) * b + m * a <= y) {
        ++ans;
    } else if (n * a + (m + 1) * b <= x && n * b + (m + 1) * a <= y) {
        ++ans;
    }
    cout << ans << endl;
}

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}