#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, h;

void read() {
    cin >> n >> h;
}

const int MAXN = 35 + 1;

ll dp[MAXN][MAXN][MAXN];

void calc() {
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < MAXN; k++)
                dp[i][j][k] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][i][1] = 1;
    }

    for (int r = 1; r <= n; r++) {
        for (int l = r - 1; l >= 1; l--) {
            for (int h = 2; h <= r - l + 1; h++) {
                dp[l][r][h] = dp[l + 1][r][h - 1] + dp[l][r - 1][h - 1];
                //cout << l << " " << r << " " << h << " " << dp[l][r][h] << endl;
                for (int mid = l + 1; mid < r; mid++) {
                    for (int hl = 1; hl < h; hl++) {
                        for (int hr = 1; hr < h; hr++) {
                            if (max(hl, hr) + 1 != h) continue;
                            dp[l][r][h] += dp[l][mid - 1][hl] * dp[mid + 1][r][hr];
                        }
                    }
                }
            }
        }
    }

    /*cout << "dp = " << endl;
    for (int h = 1; h <= n; h++) {
        cout << "h = " << h << endl;
        for (int l = 1; l <= n; l++) {
            for (int r = 1; r <= n; r++) {
                cout << dp[l][r][h] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/
}

ll ans;

void make_ans() {
    ans = 0;
    for (int x = h; x <= n; x++) {
        ans += dp[1][n][x];
    }
}

void run() {
    calc();
    make_ans();
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