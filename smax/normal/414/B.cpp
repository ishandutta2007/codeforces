#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> divisors[2000];
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j+=i)
            divisors[j-1].push_back(i);

    int dp[2000][2000] = {};
    for (int j=0; j<n; j++)
        dp[0][j] = 1;
    for (int i=1; i<k; i++)
        for (int j=0; j<n; j++)
            for (int kk : divisors[j])
                dp[i][j] = (dp[i][j] + dp[i-1][kk-1]) % MOD;

    int ret = 0;
    for (int j=0; j<n; j++)
        ret = (ret + dp[k-1][j]) % MOD;

    cout << ret << "\n";

    return 0;
}