#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;

// dp[pos][pre][num]

int main()
{
    int n, k, x, A[MAXN];
    cin >> n >> k >> x;
    long long dp[MAXN][MAXN][MAXN];
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    if(k == 1 && x < n)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int pos = 1; pos <= n; pos++)
    {
        for(int num = 1; num <= x; num++)
        {
            for(int pre = 1; pre <= k; pre++)
            {
                if(dp[pos - 1][pre][num - 1] > 0 || (num == 1 && pos <= k))
                    dp[pos][1][num] = max(dp[pos][1][num], dp[pos - 1][pre][num - 1] + A[pos]);
                if(pre > 1)
                    dp[pos][pre][num] = dp[pos - 1][pre - 1][num];
            }
        }
    }
    long long ans = 0;
    /*for(int pos = 1; pos <= n; pos++)
    {
        for(int pre = 1; pre <= k; pre++)
        {
            for(int num = 1; num <= x; num++)
                cout << pos << ", " << pre << ", " << num << ": " << dp[pos][pre][num] << endl;
        }
    }*/
    for(int pre = 1; pre <= k; pre++)
        ans = max(ans, dp[n][pre][x]);
    if(ans == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
}