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
    int n, k;
    cin >> n >> k;
    const int maxcap = (n + k - 2) / (k - 1);
    vector<vector<int>> pos(n);
    vector<int> v(n * k), ord(n * k);
    for (int i = 0; i < n * k; ++i) {
        cin >> v[i];
        --v[i];
        ord[i] = len(pos[v[i]]);
        pos[v[i]].pb(i);
    }
    vector<pii> ans(n, {-1, -1});
    vector<int> cov(n * k, 0);
    for (int i = 0; i < n * k; ++i) {
        if (ord[i] == 0 || ans[v[i]] != mp(-1, -1)) continue;
        if (*max_element(cov.begin() + pos[v[i]][ord[i] - 1], cov.begin() + i) < maxcap) {
            ans[v[i]] = {pos[v[i]][ord[i] - 1], i};
            for (int j = ans[v[i]].first; j <= ans[v[i]].second; ++j) {
                ++cov[j];
            }
        }
    }
    for (auto& [l, r] : ans) {
        assert(l != -1);
        cout << l + 1 << " " << r + 1 << endl;
    }
}