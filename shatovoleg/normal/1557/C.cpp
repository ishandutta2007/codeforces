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

constexpr int mod = 1e9 + 7;

vector<int> fact, rfact, rev;

void init() {
    constexpr int maxn = 2e5 + 1;
    fact.resize(maxn, 1);
    rfact.resize(maxn, 1);
    rev.resize(maxn, 1);
    rev[0] = 0;
    for (int i = 2; i < maxn; ++i) {
        fact[i] = int(1ll * fact[i - 1] * i % mod);
        rev[i] = mod - int(1ll * (mod / i) * rev[mod % i] % mod);
        rfact[i] = int(1ll * rfact[i - 1] * rev[i] % mod);
    }
}

int C(int n, int k) {
    int denom = int(1ll * rfact[k] * rfact[n - k] % mod);
    return int(1ll * fact[n] * denom % mod);
}

void run() {
    init();
    int t;
    cin >> t;
    while (t --> 0) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        int cur = 1;
        int cnt = (n & 1);
        for (int i = 0; i < n; i += 2) {
            if ((cnt += C(n, i)) >= mod) {
                cnt -= mod;
            }
        }
        for (int i = 0; i < k; ++i) {
            if (!(n & 1)) {
                ans += int(1ll * cur * bpow(2, 1ll * (k - i - 1) * n, mod) % mod);
                if (ans >= mod) {
                    ans -= mod;
                }
            }
            cur = int(1ll * cur * cnt % mod);
        }
        cout << (cur + ans) % mod << endl;
    }

}