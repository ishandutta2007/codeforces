#include <bits/stdc++.h>
using namespace std;

int a[200000], b[200000], dp[200000][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, c;
    cin >> n >> c;
    for (int i=0; i<n-1; i++)
        cin >> a[i];
    for (int i=0; i<n-1; i++)
        cin >> b[i];

    dp[0][0] = 0;
    dp[0][1] = 2e8;
    for (int i=0; i<n-1; i++) {
        dp[i+1][0] = min(dp[i][0] + a[i], dp[i][1] + a[i]);
        dp[i+1][1] = min(dp[i][0] + b[i] + c, dp[i][1] + b[i]);
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << "\n";

    return 0;
}