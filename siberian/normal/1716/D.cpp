#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        return a - MOD;
    }
    return a;
}

const int N = 2e5 + 10;

int n, k;
int dp[N];
int ans[N];
int it = 0;

void relax() {
    int step = k + it;
    for (int i = 0; i < k + it && i <= n; ++i) {
        int cur_val = 0;
        for (int pos = i; pos <= n; pos += step) {
            int nxt_val = add(cur_val, dp[pos]);
            dp[pos] = cur_val;
            cur_val = nxt_val;
        }
    }
    ++it;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> k;
    fill(dp, dp + n + 1, 0);
    fill(ans, ans + n + 1, 0);
    dp[0] = 1;
    while (*max_element(dp, dp + n + 1) != 0) {
        relax();
        for (int i = 1; i <= n; ++i) {
            ans[i] = add(ans[i], dp[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}