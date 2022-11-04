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

bool cmp(pair<int, int> a, pair<int, int> b) {
    return 1ll * a.first * b.second < 1ll * b.first * a.second;
}

void run() {
    int n;
    cin >> n;
    vector<pair<int, vector<int>>> msgs;
    int maxk = 0;
    {
        map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            int a, k;
            cin >> a >> k;
            m[a].pb(k);
            cmax(maxk, k);
        }
        msgs = vector<pair<int, vector<int>>>(all(m));
    }
    const int m = len(msgs);
    pair<int, int> exp = {0, 1};
    vector<int> ans;
    vector<pair<int, int>> buf(m);
    for (int c = 1; c <= maxk + 3 && c <= m; ++c) {
        for (int j = 0; j < m; ++j) {
            buf[j].second = msgs[j].first;
            buf[j].first = 0;
            for (auto& x : msgs[j].second) {
                buf[j].first += min(x, c);
            }
        }
        nth_element(buf.begin(), buf.end() - c, buf.end());
        reverse(all(buf));
        int sm = 0;
        for (int j = 0; j < c; ++j) {
            sm += buf[j].first;
        }
        if (cmp(exp, {sm, c})) {
            exp = {sm, c};
            ans.resize(c);
            for (int i = 0; i < c; ++i) {
                ans[i] = buf[i].second;
            }
        }
    }
    cout << len(ans) << endl;
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}