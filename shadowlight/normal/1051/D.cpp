#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int MOD = 998244353;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = 1007;

int dp[N][2 * N][4];

const int T = 4;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 4; i++) {
        if (!i || i == 3) {
            dp[1][1][i] = 1;
        } else {
            dp[1][2][i] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int c = 0; c <= k; c++) {
            for (int ma = 0; ma < 4; ma++) {
                for (int mb = 0; mb < 4; mb++) {
                    int cnt = 0;
                    if (mb % 2 == mb / 2) {
                        cnt++;
                    }
                    if (mb % 2 == ma % 2) {
                        cnt++;
                    }
                    if (mb / 2 == ma / 2) {
                        cnt++;
                    }
                    int d = max(2 - cnt, 0);
                    add(dp[i][c + d][mb], dp[i - 1][c][ma]);
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < T; i++) {
        add(sum, dp[n][k][i]);
    }
    cout << sum;
}