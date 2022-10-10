#include <bits/stdc++.h>
using namespace std;

int memo[505][505], arr[505], n;

int dp(int i, int j) {
    if(i > j)
        return 0;
    if(i == j)
        return 1;
    if(memo[i][j] != -1)
        return memo[i][j];
    int ans = 10000000;
    for(int p = i; p <= j; p++) {
        if(p < j)
            ans = min(ans, dp(i, p) + dp(p + 1, j));
        if(p > i && arr[i] == arr[p])
            ans = min(ans, max(1, dp(i + 1, p - 1)) + dp(p + 1, j));
    }
    return memo[i][j] = ans;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    memset(memo, -1, sizeof memo);
    cout << dp(1, n) << endl;
}