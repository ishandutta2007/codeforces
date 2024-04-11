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

// #ifdef LOCAL
// constexpr int K = 2;
// #else
constexpr int K = 450;
// #endif

struct BulkAddArray {
    vector<int> arr;
    array<array<vector<array<int, 3>>, K>, K> groupdAdd;

    BulkAddArray(int n) : arr(n, 0) {}

    void add(int start, int step, int cnt, int val) {
        if (cnt < K) {
            for (int i = 0; i < cnt; ++i) {
                arr[start] += val;
                start += step;
            }
        } else {
            assert(step < K);
            groupdAdd[step][start % step].pb({start / step, cnt, val});
        }
    }

    vector<int> get() const {
        vector<int> res(arr);
        vector<int> tmp(len(arr) + 1, 0);
        for (int step = 1; step < K; ++step) {
            for (int shift = 0; shift < step; ++shift) {
                int mx = 0;
                for (auto& [start, cnt, val] : groupdAdd[step][shift]) {
                    tmp[start] += val;
                    tmp[start + cnt] -= val;
                    cmax(mx, start + cnt);
                }
                int sm = 0;
                for (int i = 0; i <= mx; ++i) {
                    sm += tmp[i];
                    tmp[i] = 0;
                    int idx = shift + step * i;
                    if (idx < len(res)) [[ likely ]] {
                        res[idx] += sm;
                    }
                }
            }
        }
        return res;
    }
};

void run() {
    int n, m;
    cin >> n >> m;
    vector<pii> trains(n);
    for (auto& [x, y] : trains) {
        cin >> y >> x;
    }

    vector<int> placed(n, -1);
    BulkAddArray res(m + 1);

    auto add_train = [&](int day, int type) {
        placed[type] = day;
    };

    auto remove_train = [&](int day, int type) {
        int added = placed[type] + trains[type].second;
        placed[type] = -1;
        if (added >= day) {
            return;
        }

        int cycle_len = trains[type].first + trains[type].second;

        int full_cycles = (day - added) / cycle_len;
        res.add(added, cycle_len, full_cycles, 1);
        res.add(added + trains[type].first, cycle_len, full_cycles, -1);
        added += full_cycles * cycle_len;
        res.add(added, cycle_len, 1, 1);
        res.add(min(added + trains[type].first, day), cycle_len, 1, -1);
    };

    for (int i = 0; i < m; ++i) {
        int op, k;
        cin >> op >> k;
        --k;
        if (op == 1) {
            add_train(i, k);
        } else {
            remove_train(i, k);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (placed[i] != -1) {
            remove_train(m, i);
        }
    }

    vector<int> ans = res.get();
    partial_sum(all(ans), ans.begin());
    ans.pop_back();
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}