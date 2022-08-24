#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 5100;

int N, M, K;
int latest[MAXN];

int a[MAXN], b[MAXN], c[MAXN];
int dp[MAXN][MAXN]; // total value with these guys

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i] >> c[i];

    for (int i = 0; i < N; i++)
        latest[i] = i;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        latest[y] = max (latest[y], x);
    }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = -1e9;
    dp[0][K] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = a[i]; j < MAXN; j++)
            if (dp[i][j] >= 0)
            {
                dp[i+1][j+b[i]] = max (dp[i+1][j+b[i]], dp[i][j]);
            }
        for (int j = 0; j <= i; j++)
            if (latest[j] == i)
            {
                for (int k = 1; k < MAXN; k++)
                {
                    if (dp[i+1][k] >= 0)
                    {
                        dp[i+1][k-1] = max (dp[i+1][k-1], dp[i+1][k] + c[j]);
                    }
                }
            }
    }

    int res = -1;
    for (int i = 0; i < MAXN; i++)
        res = max (res, dp[N][i]);
    cout << res << "\n";
}