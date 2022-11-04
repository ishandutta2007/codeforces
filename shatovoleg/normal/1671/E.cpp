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

template<class T, class U>
istream& operator>>(istream& in, std::pair<T, U>& p);

template<class T>
istream& operator>>(istream& in, vector<T>& v);

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

constexpr int mod = 998'244'353;

void run() {
    const int r1 = int(rnd() % (mod - 100) + 50), r2 = int(rnd() % (mod - 100) + 50);
    assert(r1 > 0 && r2 > 0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp((1 << n) - 1, 1);
    vector<int> hash((1 << n) - 1, 0);
    for (int i = (1 << n) - 2; i > -1; --i) {
        if (2 * i + 1 >= len(s)) {
            hash[i] = (s[i] - 'A' + r2);
            hash[i] += dp[i];
            continue;
        }
        dp[i] = int(1ll * dp[2 * i + 1] * dp[2 * i + 2] % mod);
        if (hash[2 * i + 1] != hash[2 * i + 2]) {
            dp[i] <<= 1;
            if (dp[i] >= mod) {
                dp[i] -= mod;
            }
        }
        hash[i] = int(1ll * (hash[2 * i + 1] + r1) * (hash[2 * i + 2] + r1) % mod);
        hash[i] += int(1ll * (s[i] - 'A' + r2) * (hash[2 * i + 1] + hash[2 * i + 2]) % mod);
        if (hash[i] >= mod) {
            hash[i] -= mod;
        }
        hash[i] += dp[i];
        if (hash[i] >= mod) {
            hash[i] -= mod;
        }
    }
    cout << dp[0] << endl;
}