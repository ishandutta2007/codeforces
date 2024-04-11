#include "bits/stdc++.h"

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


const int INF = (is_same<int, ll>::value ? 3e18l + 666 : 1e9 + 666);
const ll INFll = 3e18l + 666;
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

void run();

// #define TASK "dreamrun"

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

const size_t random_val = (rnd() << 32) | rnd();

namespace std {
    template<>
    struct hash<pii> {
        size_t operator()(pii v) const {
            return (size_t(v.first) ^ random_val) + size_t(v.second);
        }
    };
}

void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a == b + 1 && b != (n >> 1)) {
            cout << -1 << endl;
            continue;
        }
        if (a == b + 1) {
            vector<int> p(n);
            iota(all(p), 1);
            reverse(all(p));
            for (auto& x : p) {
                cout << x << " ";
            }
            cout << endl;
            continue;
        }
        if (n - b > (n >> 1) - 1 || a - 1 > (n >> 1) - 1 || a > b + 1) {
            cout << -1 << endl;
            continue;
        }
        vector<int> p(n);
        iota(p.begin(), p.begin() + (n - b), b + 1);
        iota(p.begin() + (n - b), p.end() - a + 1, a);
        iota(p.end() - a + 1, p.end(), 1);
        for (auto& x : p) {
            cout << x << " ";
        }
        cout << endl;
    }
}