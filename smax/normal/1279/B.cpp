#include <bits/stdc++.h>
using namespace std;

int a[100000], skip[100000][2];
long long dp[100000][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        for (int i=0; i<n; i++)
            cin >> a[i];

        int mx = 0, ret;
        for (int i=0; i<n; i++) {
            dp[i][0] = (i > 0 ? dp[i-1][0] : 0) + a[i];
            skip[i][0] = -1;
            if (i == 0) {
                dp[i][1] = 0;
                skip[i][1] = 0;
            } else if (dp[i-1][0] < dp[i-1][1] + a[i]) {
                dp[i][1] = dp[i-1][0];
                skip[i][1] = i;
            } else {
                dp[i][1] = dp[i-1][1] + a[i];
                skip[i][1] = skip[i-1][1];
            }
            if (dp[i][0] <= s && i + 1 > mx)
                mx = i + 1, ret = skip[i][0];
            if (dp[i][1] <= s && i > mx)
                mx = i, ret = skip[i][1];
        }

        cout << ret + 1 << "\n";
    }

    return 0;
}