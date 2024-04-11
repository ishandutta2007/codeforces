#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const ll MOD = 1e9 + 7;

int T, K;
ll dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> T >> K;
    dp[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        dp[i] = dp[i-1];
        if (i >= K) dp[i] = (dp[i] + dp[i-K]) % MOD;
    }

    for (int i = 1; i < MAXN; i++)
    {
        dp[i] = (dp[i] + dp[i-1]) % MOD;
    }

    for (int i = 0; i < T; i++)
    {
        int a, b; cin >> a >> b;
        ll res = (dp[b] - dp[a-1] + MOD) % MOD;
        cout << res << "\n";
    }
}