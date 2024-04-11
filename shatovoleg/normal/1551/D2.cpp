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
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> fld(n, string(m, '.'));

    auto place_domino = [&fld, n, m](int x, int y, bool hor) {
        auto get_neighbours = [&fld, n, m](int x, int y) {
            string res;
            if (x > 0 && fld[x - 1][y] != '.') {
                res += fld[x - 1][y];
            }
            if (y > 0 && fld[x][y - 1] != '.') {
                res += fld[x][y - 1];
            }
            if (x + 1 < n && fld[x + 1][y] != '.') {
                res += fld[x + 1][y];
            }
            if (y + 1 < m && fld[x][y + 1] != '.') {
                res += fld[x][y + 1];
            }
            return res;
        };

        string s = get_neighbours(x, y);
        assert(fld[x][y] == '.');
        if (hor) {
            s += get_neighbours(x, y + 1);
            assert(fld[x][y + 1] == '.');
        } else {
            s += get_neighbours(x + 1, y);
            assert(fld[x + 1][y] == '.');
        }
        sort(all(s));
        s.resize(unique(all(s)) - s.begin());

        char sym = 0;
        for (int i = 0; i < len(s); ++i) {
            if (s[i] != 'a' + i) {
                sym = char('a' + i);
                break;
            }
        }
        if (sym == 0) {
            sym = char('a' + len(s));
        }
        fld[x][y] = sym;
        if (hor) {
            fld[x][y + 1] = sym;
        } else {
            fld[x + 1][y] = sym;
        }
    };

    if (n & 1) {
        if (k < (m >> 1)) {
            cout << "NO" << endl;
            return;
        }
        k -= (m >> 1);
        for (int i = 0; i < m; i += 2) {
            place_domino(n - 1, i, 1);
        }
        --n;
    }
    if (m & 1) {
        for (int i = 0; i < n; i += 2) {
            place_domino(i, m - 1, 0);
        }
        --m;
    }
    if ((k & 1) || (k << 1) > n * m) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            if (k > 0) {
                place_domino(i, j, 1);
                place_domino(i + 1, j, 1);
                k -= 2;
            } else {
                place_domino(i, j, 0);
                place_domino(i, j + 1, 0);
            }
        }
    }
    for (auto& line : fld) {
        cout << line << endl;
    }
}