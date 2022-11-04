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

void run() {
    constexpr ll INF = 5e18;
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> fld(n, vector<int>(m));
    for (auto& line : fld) {
        for (auto& v : line) {
            cin >> v;
        }
    }
    vector<ll> dist(n * m + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    dist[0] = 0;
    q.push({0, 0});
    auto relax = [&](int v, ll d) {
        if (cmin(dist[v], d)) {
            q.push({d, v});
        }
    };
    while (len(q)) {
        auto [d, v] = q.top();
        q.pop();
        if (dist[v] < d) continue;
        if (v == n * m) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (fld[i][j] > 0) {
                        relax(i * m + j, d + fld[i][j]);
                    }
                }
            }
        } else {
            int x = v / m, y = v % m;
            if (x + 1 < n && fld[x + 1][y] != -1) {
                relax(v + m, d + w);
            }
            if (y + 1 < m && fld[x][y + 1] != -1) {
                relax(v + 1, d + w);
            }
            if (y - 1 >= 0 && fld[x][y - 1] != -1) {
                relax(v - 1, d + w);
            }
            if (x - 1 >= 0 && fld[x - 1][y] != -1) {
                relax(v - m, d + w);
            }
            if (fld[x][y] > 0) {
                relax(n * m, d + fld[x][y]);
            }
        }
    }
    if (dist[n * m - 1] == INF) {
        dist[n * m - 1] = -1;
    }
    cout << dist[n * m - 1] << endl;
}