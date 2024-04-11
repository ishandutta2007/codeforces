#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, t;
ld p;

void read() {
    cin >> n >> p >> t;        
}

const int MAXN = 2010;
ld dp[MAXN][MAXN];
ld ans;

void run() {
    dp[0][0] = 1;
    for (int i = 1; i <= t; i++) {
        for (int cnt = 0; cnt <= n; cnt++) {
            if (cnt != n) {
                dp[i][cnt] += dp[i - 1][cnt] * (1 - p);
            } else {
                dp[i][cnt] += dp[i - 1][cnt];
            }
            if (cnt > 0) dp[i][cnt] += dp[i - 1][cnt - 1] * p;
        }
    }

    /*cout << "dp = " << endl;
    for (int i = 0; i <= t; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[t][i] * i;
    }
}

void write() {
    cout.precision(20);
    cout.setf(ios::fixed);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}