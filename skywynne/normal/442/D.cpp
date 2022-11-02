#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, P[N], MX[N][2], dp[N];
int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n + 1; i++)
    {
        scanf("%d", &P[i]);
        for (int v = i; v > 1; v = P[v])
        {
            int _dp = max(MX[v][0], MX[v][1] + 1);
            if (_dp <= dp[v]) break;
            dp[v] = _dp;
            if (MX[P[v]][1] < _dp)
                MX[P[v]][1] = _dp;
            if (MX[P[v]][0] < MX[P[v]][1])
                swap(MX[P[v]][0], MX[P[v]][1]);
        }
        printf("%d ", MX[1][0]);
    }
    return 0;
}