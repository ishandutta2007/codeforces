#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1010, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, dp[N];
string A[2];
int main()
{
    cin >> A[0];
    cin >> A[1];
    n = A[0].size();
    A[0] = "X" + A[0];
    A[1] = "X" + A[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (A[0][i] == 'X' && A[1][i] == 'X')
            continue;
        dp[i] = max(dp[i], dp[i - 2] + (bool)(A[0][i - 1] != 'X' && A[1][i - 1] != 'X'));
        if (A[0][i] != 'X' && A[1][i] != 'X')
        {
            dp[i] = max(dp[i], dp[i - 2] + (bool)(A[0][i - 1] != 'X' || A[1][i - 1] != 'X'));
            if (A[0][i - 1] != 'X' && A[1][i - 1] != 'X' && A[0][i - 2] != 'X' && A[1][i - 2] != 'X')
                dp[i] = max(dp[i - 3] + 2, dp[i]);
        }
    }
    printf("%d", dp[n]);
    return (0);
}