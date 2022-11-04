// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

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
#define int ll

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

int bpow(int a, int b, int mod) {
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

array<int, 3> gcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, xx, yy] = gcd(b, a % b);
    return {g, yy, xx - yy * (a / b)};
}

int divup(int a, int b) {
    if (a >= 0) {
        return (a + b - 1) / b;
    }
    return a / b;
}

void run() {
    int n, m, k;
    cin >> n >> m >> k;
    const int c = 2 * max(n, m);
    vector<vector<int>> occur(2, vector<int>(c, -1));
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        --v;
        occur[0][v] = i;
    }
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        --v;
        occur[1][v] = i;
    }

    const auto [g, x, y] = gcd(n, m);
    const int nmg = m / g * n;
    vector<pii> magic(c, {-INF, -INF});
    for (int i = 0; i < c; ++i) {
        int a = occur[0][i], b = occur[1][i];
        if (a == -1 || b == -1) continue;
        if ((b - a) % g) continue;
        int s = (b - a) / g * x;
        magic[i].first = -a - n * s;
        magic[i].second = divup(-a - n * s, nmg);
    }

    auto calc = [&](int d) {
        int ans = d;
        for (int i = 0; i < c; ++i) {
            if (magic[i].first == -INF) continue;
            ans -= divup(d + magic[i].first, nmg) - magic[i].second;
        }
        return ans;
    };

    int l = 0, r = INF;
    while (r - l > 1) {
        int c = (r + l) >> 1;
        if (calc(c) >= k) {
            r = c;
        } else {
            l = c;
        }
    }
    cout << r << endl;
}