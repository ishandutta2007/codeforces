#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[10][1000][1000] = {};

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int a=0; a<n; a++)
        for (int b=a; b<n; b++)
            dp[0][a][b] = 1;
    for (int i=0; i<m; i++)
        for (int a=0; a<n; a++)
            for (int b=0; b<n; b++) {
                if (a > 0) add(dp[i][a][b], dp[i][a-1][b]);
                if (b > 0) add(dp[i][a][b], dp[i][a][b-1]);
                if (a > 0 && b > 0) sub(dp[i][a][b], dp[i][a-1][b-1]);
                if (i > 0 && a <= b) {
                    add(dp[i][a][b], dp[i-1][a][n-1]);
                    if (b > 0) sub(dp[i][a][b], dp[i-1][a][b-1]);
                }
            }

    cout << dp[m-1][n-1][n-1] << "\n";

    return 0;
}