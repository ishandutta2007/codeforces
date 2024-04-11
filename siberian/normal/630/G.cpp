#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 510;
int n;

void read() {
    cin >> n;
}

ll dp[MAXN][6][4];
ll ans;

void run() {
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int cnt1 = 0; cnt1 <= 5; cnt1++) {
            for (int cnt2 = 0; cnt2 <= 3; cnt2++) {
                for (int last1 = 0; last1 <= cnt1; last1++) {
                    for (int last2 = 0; last2 <= cnt2; last2++) {
                        dp[i][cnt1][cnt2] += dp[i - 1][last1][last2];
                    }
                }
            }
        }
    }
    ans = dp[n][5][3];
}

void write() {
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