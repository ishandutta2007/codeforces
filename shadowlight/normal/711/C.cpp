#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const long long INF = 1e18 + 8;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector <long long> data(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> data[i];
        data[i]--;
    }
    vector <vector <long long> > cost(n, vector <long long> (m, 0));
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    vector <vector <vector <long long> > > dp(n, vector <vector <long long> > (m, vector <long long> (k + 7, INF)));
    if (data[0] != -1) {
        dp[0][data[0]][1] = 0;
    } else {
        for (long long j = 0; j < m; j++) {
            dp[0][j][1] = cost[0][j];
        }
    }
    for (long long i = 1; i < n; i++) {
        for (long long l = 1; l <= k; l++) {
            if (data[i] != -1) {
                dp[i][data[i]][l] = dp[i - 1][data[i]][l];
                for (long long j = 0; j < m; j++) {
                    if (j != data[i]) dp[i][data[i]][l] = min(dp[i][data[i]][l], dp[i - 1][j][l - 1]);
                }
            } else {
                for (long long e = 0; e < m; e++) {
                    for (long long j = 0; j < m; j++) {
                        if (e == j) {
                            dp[i][e][l] = min(dp[i][e][l], dp[i - 1][e][l] + cost[i][e]);
                        } else {
                            dp[i][e][l] = min(dp[i][e][l], dp[i - 1][j][l - 1] + cost[i][e]);
                        }
                    }
                }
            }
        }
    }
    long long mink = INF;
    for (long long i = 0; i < m; i++) {
        mink = min(mink, dp[n - 1][i][k]);
    }
    if (mink == INF) {
        cout << -1;
    } else {
        cout << mink;
    }
}