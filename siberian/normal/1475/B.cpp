#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 1e6 + 10;
bool dp[N];

void build() {
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        dp[i] = false;
        if (i >= 2020 && dp[i - 2020]) dp[i] = 1;
        if (i >= 2021 && dp[i - 2021]) dp[i] = 1;
    }
}

void solve() {
    int n;
    cin >> n;
    if (dp[n]) cout << "YES\n";
    else cout << "NO\n";
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