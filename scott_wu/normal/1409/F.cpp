#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 210;

int N, K;
string s, t;
char a, b;
int dp[MAXN][MAXN][MAXN]; // i changes, j a's

void gogo()
{
    cin >> N >> K;
    cin >> s >> t;
    a = t[0];
    b = t[1];

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < MAXN; k++)
            dp[i][j][k] = -1e6;

    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
            for (int k = 0; k <= N; k++)
            {
                int nk = k, nv = dp[i][j][k];
                if (s[i] == b)
                    nv += k;
                if (s[i] == a)
                    nk += 1;
                dp[i+1][j][nk] = max (dp[i+1][j][nk], nv);

                {
                    nk = k + 1;
                    nv = dp[i][j][k];
                    if (a == b) nv = nv + k;
                    dp[i+1][j+1][nk] = max (dp[i+1][j+1][nk], nv);
                }
                {
                    nk = k;
                    nv = dp[i][j][k] + k;
                    dp[i+1][j+1][nk] = max (dp[i+1][j+1][nk], nv);
                }
            }
    }
    int ans = 0;
    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= N; j++)
            ans = max (ans, dp[N][i][j]);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    gogo();
}