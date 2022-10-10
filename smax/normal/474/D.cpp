#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[100001], prefixSum[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t, k;
    cin >> t >> k;

    dp[0] = 1;
    prefixSum[0] = 0;
    for (int i=1; i<=100000; i++) {
        dp[i] = (dp[i-1] + (i >= k ? dp[i-k] : 0)) % MOD;
        prefixSum[i] = (prefixSum[i-1] + dp[i]) % MOD;
    }

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << ((prefixSum[b] - prefixSum[a-1]) % MOD + MOD) % MOD << "\n";
    }

    return 0;
}