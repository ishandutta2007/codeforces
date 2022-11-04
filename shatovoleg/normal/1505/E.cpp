// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair
// #define int ll

#define debug(x) cout << #x << " = " << x << endl;

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

void run() {
    int n, m;
    cin >> n >> m;
    vector<string> fld(n);
    for (auto& x : fld) {
        cin >> x;
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp.back().back() = (fld.back().back() == '*');
    for (int i = n - 2; i > -1; --i) {
        dp[i].back() = dp[i + 1].back() + (fld[i].back() == '*');
    }
    for (int j = m - 2; j > -1; --j) {
        dp.back()[j] = dp.back()[j + 1] + (fld.back()[j] == '*');
    }
    for (int i = n - 2; i > -1; --i) {
        for (int j = m - 2; j > -1; --j) {
            if (fld[i + 1][j] != fld[i][j + 1]) {
                if (fld[i + 1][j] == '*') {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i][j + 1];
                }
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);
            }
            if (fld[i][j] == '*') {
                ++dp[i][j];
            }
        }
    }
    cout << dp[0][0] << endl;
}