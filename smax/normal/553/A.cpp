#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int c[1000], pre[1000], dp[1000], choice[2000][2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> c[i];
        pre[i] = c[i] + (i > 0 ? pre[i-1] : 0);
    }

    for (int i=0; i<2000; i++)
        choice[i][0] = 1;
    for (int j=1; j<2000; j++)
        choice[0][j] = 0;
    for (int i=1; i<2000; i++)
        for (int j=1; j<2000; j++)
            choice[i][j] = (choice[i-1][j-1] + choice[i-1][j]) % MOD;

    dp[0] = 1;
    for (int i=1; i<k; i++)
        dp[i] = (long long) dp[i-1] * choice[pre[i-1]+c[i]-1][c[i]-1] % MOD;

    cout << dp[k-1] << "\n";

    return 0;
}