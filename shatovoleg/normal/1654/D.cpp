#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
// typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll

const int INF = (is_same<int, ll>::value ? 4e18l + 666 : 1e9 + 666);
const ll INFll = 4e18l + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

template<class T, class U>
istream& operator>>(istream& in, std::pair<T, U>& p) {
    return in >> p.first >> p.second;
}

template<class TLambda>
struct YPredicate {
    YPredicate(TLambda&& l) : l_(l) {}

    template<class... TArgs>
    auto operator()(TArgs&&... args) {
        return l_(*this, std::forward<TArgs>(args)...);
    }

private:
    TLambda l_;
};

void run();

// #define TASK "taskname"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
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

constexpr int mod = 998244353;

vector<int> ld, primes;
vector<int> rev;

void init(int n) {
    ++n;
    ld.assign(n, -1);
    primes.clear();

    for (int i = 2; i < n; ++i) {
        if (ld[i] == -1) {
            ld[i] = i;
            primes.pb(i);
        }
        for (int j = 0; j < len(primes) && i * primes[j] < n && primes[j] <= ld[i]; ++j) {
            ld[i * primes[j]] = primes[j];
        }
    }

    rev.assign(n, -1);
    rev[0] = 0;
    rev[1] = 1;
    for (int i = 2; i < n; ++i) {
        rev[i] = mod - int(1ll * (mod / i) * rev[mod % i] % mod);
        // assert(1ll * rev[i] * i % mod == 1);
    }
}

vector<int> to_primes(int n) {
    vector<int> primes;
    while (n > 1) {
        primes.pb(ld[n]);
        n /= ld[n];
    }
    return primes;
}

void solve() {
    int n;
    cin >> n;
    init(n);
    vector<vector<tuple<int, vector<int>, vector<int>>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        --u, --v;
        swap(x, y);
        vector<int> xx = to_primes(x);
        vector<int> yy = to_primes(y);
        g[u].emplace_back(v, xx, yy);
        g[v].emplace_back(u, yy, xx);
        // au = av * x / y
    }

    vector<int> maxpow(n + 1, 0);
    vector<int> curpow(n + 1, 0);
    auto dfs = YPredicate([&](auto dfs, int v, int p = -1) -> void {
        for (auto& [u, x, y] : g[v]) {
            if (u == p) continue;
            for (auto val : x) {
                ++curpow[val];
            }
            for (auto val : y) {
                cmin(maxpow[val], --curpow[val]);
            }
            dfs(u, v);
            for (auto val : x) {
                --curpow[val];
            }
            for (auto val : y) {
                ++curpow[val];
            }
        }
    });
    dfs(0);
    ll val = 1;
    for (int i = 1; i <= n; ++i) {
        (val *= bpow(i, -maxpow[i], mod)) %= mod;
    }
    ll sm = 0;
    auto dfs2 = YPredicate([&](auto dfs2, int v, ll val, int p = -1) -> void {
        sm += val;
        for (auto& [u, x, y] : g[v]) {
            if (u == p) continue;
            ll newval = val;
            for (auto val : x) {
                newval *= val;
            }
            newval %= mod;
            for (auto val : y) {
                (newval *= rev[val]) %= mod;
            }
            dfs2(u, newval, v);
        }
    });
    dfs2(0, val);
    cout << sm % mod << '\n';
}