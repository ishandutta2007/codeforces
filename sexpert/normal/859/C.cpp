#include <bits/stdc++.h>
using namespace std;

int dp[55][2];

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    dp[n - 1][1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        dp[i][0] = min(v[i] + dp[i + 1][0], dp[i + 1][1]);
        dp[i][1] = max(v[i] + dp[i + 1][0], dp[i + 1][1]);
    }
    cout << accumulate(v.begin(), v.end(), -dp[0][1]) << " " << dp[0][1] << endl;
}