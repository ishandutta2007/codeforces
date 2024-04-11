#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m, h;
int s;
int sum;

void read() {
    cin >> n >> m >> h;
    n--;
    h--;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (i == h) {
            x--;
            s = x;
        }
        sum += x;
    }
}

const int MAXN = 110;
ld dp[MAXN][MAXN];

ld ans = 0;

void run() {
    if (sum < n) {
        cout << -1 << endl;
        exit(0);
    }
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int cnt = 0; cnt <= min(i, s); cnt++) {
            dp[i][cnt] = 0;
            if (cnt > 0) {
                ld p = (ld) (s - cnt + 1) / (sum - i + 1);
                dp[i][cnt] += dp[i - 1][cnt - 1] * p;
            } 
            ld p = 1.0 - (ld) (s - cnt) / (sum - i + 1);
            dp[i][cnt] += dp[i - 1][cnt] * p;
        }
    }

    /*cout << "dp = " << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;*/

    for (int i = 1; i <= n; i++) {
        ans += dp[n][i];
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