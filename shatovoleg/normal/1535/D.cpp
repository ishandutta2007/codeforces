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

void solve();

void run() {
    int n = 1;
    // cin >> n;
    while (n --> 0) {
        solve();
    }
}

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    reverse(all(s));
    int n = (1 << k);
    vector<int> cnt(2 * n - 1, 1);
    auto recalc = [&](int idx) {
        if (s[idx] == '?') {
            cnt[idx] = cnt[2 * idx + 1] + cnt[2 * idx + 2];
        } else {
            cnt[idx] = cnt[2 * idx + 2 - (s[idx] - '0')];
        }
    };
    for (int i = n - 2; i > -1; --i) {
        recalc(i);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int idx;
        char c;
        cin >> idx >> c;
        idx = len(s) - idx;
        s[idx] = c;
        idx = 2 * idx + 1;
        while (idx > 0) {
            idx = (idx - 1) >> 1;
            recalc(idx);
        }
        cout << cnt[0] << '\n';
    }
}