#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18 + 7;

int main() {
    long long n, m;
    cin >> n;
    vector <long long> c(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector <vector <long long> > dp(2, vector <long long> (n, INF));
    dp[0][0] = 0;
    dp[1][0] = c[0];
    string prev_s, prev_s1;
    cin >> prev_s;
    prev_s1 = prev_s;
    reverse(prev_s1.begin(), prev_s1.end());
    for (long long i = 1; i < n; i++) {
        string s, s1;
        cin >> s;
        s1 = s;
        reverse(s1.begin(), s1.end());
        if (s >= prev_s && dp[0][i - 1] != INF) {
            dp[0][i] = dp[0][i - 1];
        }
        if (s >= prev_s1 && dp[1][i - 1] != INF) {
            dp[0][i] = min(dp[0][i], dp[1][i - 1]);
        }
        if (s1 >= prev_s && dp[0][i - 1] != INF) {
            dp[1][i] = dp[0][i - 1] + c[i];
        }
        if (s1 >= prev_s1 && dp[1][i - 1] != INF) {
            dp[1][i] = min(dp[1][i], dp[1][i - 1] + c[i]);
        }
        //cout << dp[0][i] << " " << dp[1][i] << endl;
        if (dp[0][i] == INF && dp[1][i] == INF) {
            cout << -1;
            return 0;
        }
        prev_s = s;
        prev_s1 = s1;
    }
    cout << min(dp[0][n - 1], dp[1][n - 1]);
}