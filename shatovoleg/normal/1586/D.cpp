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

// #define TASK "codes"

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

int n;

int ask(const vector<int>& s, bool ans = false) {
    assert(len(s) == n);
    cout << "?!"[ans];
    for (auto& x : s) {
        cout << " " << x + 1;
    }
    cout << endl;
    int x = -1;
    if (!ans) {
        cin >> x;
        --x;
    }
    return x;
}

void run() {
    cin >> n;
    vector<int> p(n, -1);
    p.back() = 0;
    for (int last = 1; last < n; ++last) {
        vector<int> s(n, last);
        s.back() = 0;
        if (ask(s) != -1) {
            ++p.back();
        } else {
            break;
        }
    }
    // cerr << "! " << p.back() << endl;
    for (int i = 0; i < n; ++i) {
        if (i == p.back()) continue;
        vector<int> s(n, p.back() - i);
        s.back() = 0;
        int mn = *min_element(all(s));
        for (auto& x : s) {
            x -= mn;
        }
        p[ask(s)] = i;
    }
    ask(p, true);
}