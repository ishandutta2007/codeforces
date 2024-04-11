// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, m, q, A[N];
long long dp[N], MX[N * 2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> A[i];
    for (int i = 1; i <= n; i ++)
    {
        dp[i] = A[i];
        int val = A[i] - i + N;
        dp[i] = max(dp[i], A[i] + MX[val]);
        MX[val] = max(MX[val], dp[i]);
    }
    printf("%lld\n", * max_element(dp + 1, dp + n + 1));
    return 0;
}