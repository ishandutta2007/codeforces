#include <bits/stdc++.h>
using namespace std;

int a[200000], dp[200000][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, ret = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];

        dp[i][0] = (i > 0 && a[i-1] < a[i] ? dp[i-1][0] : 0) + 1;
        dp[i][1] = max((i > 1 && a[i-2] < a[i] ? dp[i-2][0] : 0), (i > 0 && a[i-1] < a[i] ? dp[i-1][1] : 0)) + 1;
        ret = max({ret, dp[i][0], dp[i][1]});
    }

    cout << ret << "\n";

    return 0;
}