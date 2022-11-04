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

vector<pii> drop_contained(vector<pii> segs) {
    sort(all(segs));
    vector<pii> new_segs;
    for (auto& [l, r] : segs) {
        if (len(new_segs) && new_segs.back().second > r) continue;
        new_segs.emplace_back(l, r);
    }
    return new_segs;
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        --x;
    }
    vector<int> first(n, -1), last(n, -1);
    for (int i = 0; i < n; ++i) {
        last[a[i]] = i;
    }
    for (int i = n - 1; i > -1; --i) {
        first[a[i]] = i;
    }
    vector<pii> segs;
    for (int i = 0; i < n; ++i) {
        if (first[i] != -1) {
            segs.emplace_back(first[i], last[i]);
        }
    }
    segs = drop_contained(segs);
    int m = len(segs);
    int cnt = 0;
    int cur = 0;
    while (cur < m) {
        if (cur == m - 1) {
            cnt += 1 + (segs[cur].first != segs[cur].second);
            break;
        }
        if (segs[cur + 1].first > segs[cur].second) {
            cnt += 1 + (segs[cur].first != segs[cur].second);
            ++cur;
            continue;
        }
        ++cnt;
        int r = segs[cur].second;
        ++cur;
        while (cur < m && segs[cur].first < r) {
            ++cur;
        }
        --cur;
    }
    int ans = n - cnt;
    cout << ans << endl;
}