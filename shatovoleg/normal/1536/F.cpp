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

constexpr int mod = 1e9 + 7;

vector<int> rev;
vector<int> fact, rfact;

void init(int n) {
    ++n;
    fact.resize(n, 1);
    rfact.resize(n, 1);
    rev.resize(n, 0);
    rev[1] = 1;
    for (int i = 2; i < n; ++i) {
        rev[i] = mod - (int)(1ll * (mod / i) * rev[mod % i] % mod);
        fact[i] = 1ll * i * fact[i - 1] % mod;
        rfact[i] = 1ll * rev[i] * rfact[i - 1] % mod;
    }
}

int C(int n, int k) {
    int denom = (int)(1ll * rfact[k] * rfact[n - k] % mod);
    return 1ll * fact[n] * denom % mod;
}

int CombRow(int n, int s) {
    return C(n - s + 1, s);
}

int CombCircle(int n, int s) {
    if (n == 2) {
        return 1 + s;
    }
    int res = CombRow(n - 1, s);
    if (s) {
        res += CombRow(n - 3, s - 1);
        if (res >= mod) res -= mod;
    }
    return res;
}

void run() {
    int n;
    cin >> n;
    init(n);
    int ans = 0;
    for (int spaces = (n & 1); (spaces << 1) <= n; spaces += 2) {
        ans += 2ll * CombCircle(n, spaces) * fact[n - spaces] % mod;
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << endl;
}