#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 52;
int dp[MAXN][MAXN][MAXN][MAXN];
int board[MAXN][MAXN], sum[MAXN][MAXN];

int qry(int l1, int l2, int r1, int r2) {
    return sum[l2][r2] - sum[l1 - 1][r2] - sum[l2][r1 - 1] + sum[l1 - 1][r1 - 1];
}

int calc(int l1, int l2, int r1, int r2) {
    if(dp[l1][l2][r1][r2] != -1) return dp[l1][l2][r1][r2];
    if(qry(l1, l2, r1, r2) == 0) return dp[l1][l2][r1][r2] = 0;
    dp[l1][l2][r1][r2] = 100;
    if(l2 - l1 == r2 - r1) dp[l1][l2][r1][r2] = r2 - r1 + 1;
    for(int i = l1; i < l2; i++)
        dp[l1][l2][r1][r2] = min(dp[l1][l2][r1][r2], calc(l1, i, r1, r2) + calc(i + 1, l2, r1, r2));
    for(int i = r1; i < r2; i++)
        dp[l1][l2][r1][r2] = min(dp[l1][l2][r1][r2], calc(l1, l2, r1, i) + calc(l1, l2, i + 1, r2));
    return dp[l1][l2][r1][r2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            board[i][j] = (c == '#' ? 1 : 0);
            sum[i][j] = board[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            for(int k = 0; k < MAXN; k++)
                for(int l = 0; l < MAXN; l++)
                    dp[i][j][k][l] = -1;

    cout << calc(1, n, 1, n) << endl;
}