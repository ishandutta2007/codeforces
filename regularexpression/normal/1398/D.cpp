#include<bits/stdc++.h>
using namespace std;

void upd(long long& x, long long y) {
    if (y > x) x = y;
}

const int N = 220;

long long dp[N][N][N];
int r[N], g[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, G, B;
    cin >> R >> G >> B;
    for (int i = 0; i < R; ++i) cin >> r[i];
    for (int i = 0; i < G; ++i) cin >> g[i];
    for (int i = 0; i < B; ++i) cin >> b[i];
    sort(r, r + R);
    sort(g, g + G);
    sort(b, b + B);
    for (int i = 0; i <= R; ++i) {
        for (int j = 0; j <= G; ++j) {
            for (int k = 0; k <= B; ++k) {
                if (i + 1 <= R) upd(dp[i + 1][j][k], dp[i][j][k]);
                if (j + 1 <= G) upd(dp[i][j + 1][k], dp[i][j][k]);
                if (k + 1 <= B) upd(dp[i][j][k + 1], dp[i][j][k]);
                if (i + 1 <= R && j + 1 <= G) upd(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
                if (i + 1 <= R && k + 1 <= B) upd(dp[i + 1][j][k + 1], dp[i][j][k] + r[i] * b[k]);
                if (j + 1 <= G && k + 1 <= B) upd(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
            }
        }
    }
    cout << dp[R][G][B];
    return 0;
}