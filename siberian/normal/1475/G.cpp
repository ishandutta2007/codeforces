#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;

vector<int> d[N];

void build() {
    for (int i = 1; i < N; ++i) {
        for (int j = i + i; j < N; j += i) {
            d[j].push_back(i);
        }
    }
}

int cnt[N];
int dp[N];

void solve() {
    fill(cnt, cnt + N, 0);
    fill(dp, dp + N, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < N; ++i) {
        if (cnt[i] == 0) continue;
        dp[i] = cnt[i];
        for (auto x : d[i]) {
            chkmax(dp[i], cnt[i] + dp[x]);
        }
    }
    // cerr << "dp = " << endl;
    // for (int i = 0; i < N; ++i) {
    //     if (dp[i]) {
    //         cerr << "i = " << i << " dp = " << dp[i] << endl;
    //     }
    // }
    cout << n - *max_element(dp, dp + N) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}