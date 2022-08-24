#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N;
int arr[MAXN];
int dp[MAXN][MAXN][2];
int nv[2];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    nv[0] = N / 2;
    nv[1] = N - nv[0];

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j][0] = dp[i][j][1] = 1e9;

    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        if (x == 0)
            arr[i] = -1;
        else
        {
            arr[i] = x % 2;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0;

    for (int i = 0; i <= nv[0]; i++)
        for (int j = 0; j <= nv[1]; j++)
        {
            int nloc = i + j;
            if (nloc == N) continue;
            for (int k = 0; k < 2; k++)
            {
                if (arr[nloc] != -1)
                {
                    if (arr[nloc] == 0)
                        dp[i+1][j][0] = min (dp[i+1][j][0], dp[i][j][k] + k);
                    else
                        dp[i][j+1][1] = min (dp[i][j+1][1], dp[i][j][k] + (1 - k));
                }
                else
                {
                    dp[i+1][j][0] = min (dp[i+1][j][0], dp[i][j][k] + k);
                    dp[i][j+1][1] = min (dp[i][j+1][1], dp[i][j][k] + (1 - k));                    
                }
            }
        }

    cout << min (dp[nv[0]][nv[1]][0], dp[nv[0]][nv[1]][1]) << "\n";
}