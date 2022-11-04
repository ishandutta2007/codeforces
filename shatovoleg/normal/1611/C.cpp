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

vector<int> check(const vector<int>& p, int first) {
    deque<int> q;
    q.push_back(first);
    int l = 0, r = len(p) - 1;
    while (r - l >= 0) {
        if (p[l] < q.back()) {
            q.push_front(p[l++]);
            continue;
        }
        if (p[r] < q.front()) {
            q.push_back(p[r--]);
            continue;
        }
        return {};
    }
    return {all(q)};
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) {
        cin >> x;
    }
    auto r1 = check({p.begin(), p.end() - 1}, p.back());
    if (!r1.empty()) {
        for (auto& x : r1) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    auto r2 = check({p.begin() + 1, p.end()}, p.front());
    if (!r2.empty()) {
        for (auto& x : r2) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    cout << "-1\n";
}