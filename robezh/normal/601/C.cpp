#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 1005;

int n, m;
int x[N];
double dp[N][2 * N * M];
double psum[2 * N * M];

double get_sum(int i, int j) {
    i = max(0, i);
    j = min(2 * n * m - 1, j);
    return psum[j] - (i == 0 ? 0 : psum[i-1]);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> x[i];
    if(m == 1) return cout << 1 << endl, 0;
    int mid = n * m;
    dp[0][mid] = 1;
    for(int i = 1; i <= n; i++) {
        psum[0] = dp[i-1][0];
        for(int j = 1; j < 2 * n * m; j++) psum[j] = psum[j-1] + dp[i-1][j];
        for(int j = 0; j < 2 * n * m; j++) {
            dp[i][j] += 1.0 / (m - 1) * (get_sum(j + x[i] - m, j + x[i] - 1) - dp[i-1][j]);
        }
    }
    double res = 0;
//    for(int j = 0; j < 2 * n * m; j++) cout << dp[n][j] << endl;
    for(int j = 0; j < mid; j++) {
//        cout << j << ": " << dp[3][j] << endl;
        res += dp[n][j];
    }
    res *= (m - 1);
    cout << fixed << setprecision(10) << res + 1 << endl;
}