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

constexpr int MAXN = 100'000;
constexpr int K = 320;
constexpr int ZERO = (K + 1) * MAXN;
constexpr int MAXC = 2 * ZERO;

const size_t RANDOM = rnd();

template<>
struct std::hash<pair<int, ll>> {
    size_t operator()(pair<int, ll> p) const {
        return p.first * RANDOM + p.second;
    };
};

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int ans = 0;
    vector<int> cnt(MAXC, 0);
    for (int k = -K; k <= K; ++k) {
        for (int i = 0; i < n; ++i) {
            cmax(ans, ++cnt[a[i] - i * k + ZERO]);
        }
        for (int i = 0; i < n; ++i) {
            --cnt[a[i] - i * k + ZERO];
        }
    }
    unordered_map<pair<int, ll>, pair<int, int>> cnt2;
    cnt2.rehash(1e7 + 666);
    for (int i = 0; i < n; ++i) {
        int l = max(i - K, 0);
        for (int j = l; j < i; ++j) {
            if ((a[i] - a[j]) % (i - j)) continue;
            cmax(ans, 2);
            int k = (a[i] - a[j]) / (i - j);
            ll b = a[i] - 1ll * k * i;
            auto [it, ins] = cnt2.emplace(mp(k, b), mp(2, i));
            if (it->second.second != i) {
                cmax(ans, ++it->second.first);
                it->second.second = i;
            }
        }
    }
    cout << n - ans << endl;
}