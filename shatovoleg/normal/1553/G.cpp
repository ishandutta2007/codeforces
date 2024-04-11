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

pii norm(pii p) {
    if (p.first > p.second) {
        swap(p.first, p.second);
    }
    return p;
}

void run() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    int maxa = *max_element(all(a));
    maxa += 2;

    vector<int> ld(maxa, -1);
    vector<int> primes;
    for (int i = 2; i < maxa; ++i) {
        if (ld[i] == -1) {
            primes.pb(ld[i] = i);
        }
        for (int j = 0; j < len(primes) && primes[j] <= ld[i] && i * primes[j] < maxa; ++j) {
            ld[i * primes[j]] = primes[j];
        }
    }

    auto get_pdivisors = [&ld, &primes](int val) {
        vector<int> res;
        res.reserve(13);
        while (val > 1) {
            if (res.empty() || res.back() != ld[val]) {
                res.pb(ld[val]);
            }
            val /= ld[val];
        }
        for (auto& x : res) {
            x = (int)(lower_bound(all(primes), x) - primes.begin());
        }
        return res;
    };

    const int m = len(primes);
    vector<vector<int>> g(n + m);
    for (int i = 0; i < n; ++i) {
        for (auto& x : get_pdivisors(a[i])) {
            g[i].pb(x + n);
            g[x + n].pb(i);
        }
    }

    vector<int> color(n + m, -1);
    function<void(int, int)> paint = [&g, &color, &paint](int v, int c) {
        color[v] = c;
        for (auto& x : g[v]) {
            if (color[x] == -1) {
                paint(x, c);
            }
        }
    };

    int c = 0;
    for (int i = 0; i < n + m; ++i) {
        if (color[i] == -1) {
            paint(i, c++);
        }
    }

    set<pii> edges;
    for (int i = 0; i < n; ++i) {
        vector<int> clrs = {color[i]};
        for (auto& x : get_pdivisors(a[i] + 1)) {
            if (color[i] != color[x + n]) {
                clrs.pb(color[x + n]);
            }
        }
        sort(all(clrs));
        clrs.resize(unique(all(clrs)) - clrs.begin());
        for (auto& x : clrs) {
            for (auto& y : clrs) {
                if (y >= x) break;
                edges.emplace(y, x);
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        if (color[s] == color[t]) {
            cout << "0\n";
        } else if (edges.count(norm({color[s], color[t]}))) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}