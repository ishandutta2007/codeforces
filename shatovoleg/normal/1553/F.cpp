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

constexpr uint K = 400;

template<class T>
struct fenv {
    vector<T> tree;

    fenv(int n) : tree(n + 1, 0) {}

    T get(int idx) const {
        ++idx;
        T sm = 0;
        for (; idx > 0; idx -= f(idx)) {
            sm += tree[idx];
        }
        return sm;
    }

    void add(int idx, T val) {
        ++idx;
        for (; idx < len(tree); idx += f(idx)) {
            tree[idx] += val;
        }
    }

    static int f(int i) {
        return i & -i;
    }
};

constexpr uint maxa = 3e5;

constexpr int K2 = 14;

void solve() {
    int n;
    cin >> n;
    vector<vector<uint>> rem_cnt(K + 1);
    for (uint i = 0; i <= K; ++i) {
        rem_cnt[i].resize(i, 0);
    }
    fenv<uint> fnumcnt(maxa + 1);
    fenv<ull> fnumsm(maxa + 1);
    vector<int> numcnt(maxa + 1, 0), numsm(maxa + 1, 0);
    ull ans = 0;
    ull num_sm = 0;
    vector<array<uint, 3>> rems;
    for (int i = 0; i < n; ++i) {
        uint v;
        cin >> v;

        if (v <= K) {
            for (uint i = 0; i < v; ++i) {
                ans += rem_cnt[v][i] * i;
            }
        } else {
            ans += num_sm;
            ull prv_cnt = 0;
            for (int s = 0; s * v <= maxa; ++s) {
                ull p = fnumcnt.get(min((s + 1) * v - 1, maxa));
                ans -= (p - prv_cnt) * s * v;
                prv_cnt = p;
            }
        }

        {
            uint prv = v;
            for (uint i = 1; i * i <= v; ++i) {
                uint nw = v / (i + 1);
                rems.pb({i, nw, prv});
                if (i != prv) {
                    rems.pb({prv, i - 1, i});
                }
                prv = nw;
            }
            rems.pb({0, v, maxa});
            // sort(all(rems));
            // reverse(all(rems));

            // ull prv_sm = 0, prv_cnt = 0;
            for (auto& [r, fr, to] : rems) {
                ull cnt, sm;
                if (to - fr <= K2) {
                    cnt = accumulate(numcnt.begin() + fr + 1, numcnt.begin() + to + 1, 0u);
                    sm = accumulate(numsm.begin() + fr + 1, numsm.begin() + to + 1, 0u);
                } else {
                    cnt = fnumcnt.get(to) - fnumcnt.get(fr);
                    sm = fnumsm.get(to) - fnumsm.get(fr);
                }
                // prv_cnt += cnt;
                // prv_sm += sm;
                ans += v * cnt - r * sm;
            }
            rems.clear();
        }

        for (uint i = 1; i <= K; ++i) {
            ++rem_cnt[i][v % i];
        }
        fnumcnt.add(v, 1);
        ++numcnt[v];
        fnumsm.add(v, v);
        numsm[v] += v;
        num_sm += v;
        cout << ans << " ";
    }
    cout << endl;
}