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

vector<int> calcZ(const string& s) {
    const int n = len(s);
    int l = 0, r = 0;
    vector<int> z(n, 0);
    z[0] = n;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
        if (cmax(r, i + z[i])) {
            l = i;
        }
    }
    return z;
}

int findMinPref(const string& s) {
    const vector<int> z = calcZ(s);
    auto cmp = [&s, &z](int p2, int p1) {
        if (p2 % p1 == 0 && z[p1] >= p2 - p1) {
            return false;
        }
        if (z[p1] < p2 - p1) {
            return s[z[p1] % p1] > s[p1 + z[p1]];
        }
        int start = p2 % p1;
        assert(start + z[start] < p1);
        return s[start + z[start]] > s[z[start]];
    };
    int best = 1;
    for (int i = 2; i <= len(s); ++i) {
        if (cmp(i, best)) best = i;
    }
    return best;
}

void run() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = findMinPref(s);
    cerr << l << endl;
    for (int i = 0; i < k; ++i) {
        cout << s[i % l];
    }
    cout << endl;
}