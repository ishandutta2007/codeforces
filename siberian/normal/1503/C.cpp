#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll
const int N = 1e5 + 10;
int n;
int a[N], c[N];
int order[N];

struct Event{
    int i, dp;
};

bool operator<(const Event& a, const Event& b) {
    return tie(a.dp, a.i) < tie(b.dp, b.i);
}

int dp[N];
int addMin[N];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> c[i];
    }
    iota(order, order + n, 0);
    sort(order, order + n, [&] (int i, int j) {
        return a[i] < a[j];
    });
    // cerr << "order = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << order[i] << " ";
    // }
    // cerr << endl;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += c[i];
    }
    // cout << "ans = " << ans << endl;
    set<Event> events;
    fill(addMin, addMin + n, (int)1e18);
    int minVal = 1e18;
    dp[0] = 0;
    events.insert({order[0], dp[0]});
    int L = 0, R = n;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (a[order[M]] - a[order[0]] <= c[order[0]]) {
            L = M;
        } else {
            R = M;
        }
    }
    chkmin(addMin[R], dp[0] - a[order[0]] - c[order[0]]);

    for (int i = 1; i < n; ++i) {
        chkmin(minVal, addMin[i]);
        // cerr << "minVal = " << minVal << endl;
        int pos = order[i];
        dp[i] = 1e18;
        chkmin(dp[i], a[pos] + minVal);
        while (!events.empty()) {
            auto it = *events.begin();
            events.erase(it);
            int posIt = it.i;
            // cerr << "a[pos] = " << a[pos] << " a[posIt] = " << a[posIt] << " c[posIt] = " << c[posIt] << endl;
            if (a[pos] - a[posIt] > c[posIt]) continue;
            chkmin(dp[i], it.dp);
            events.insert(it);
            break;
        }
        events.insert({pos, dp[i]});
        // chkmin(minVal, dp[i] - a[pos] - c[pos]);
        int L = i, R = n;
        while (L < R - 1) {
            int M = (L + R) / 2;
            if (a[order[M]] - a[pos] <= c[pos]) {
                L = M;
            } else {
                R = M;
            }
        }
        // cerr << "R = " << R << endl;
        chkmin(addMin[R], dp[i] - a[pos] - c[pos]);
    }
    // cout << "dp = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << ans + dp[n - 1] << endl;
    return 0;
}