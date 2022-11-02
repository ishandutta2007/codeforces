#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int n, m, k, r, t, p, c, P[N][N], S[N][N], M[N][N], dp[N][N];
string s;
vector < int > V[N];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '1')
                V[i].push_back(j);
        if (V[i].size() == 0)
            continue;
        M[i][0] = V[i].back() - V[i][0] + 1;
        for (int j = 1; j < (int)V[i].size(); j++)
        {
            r = 1e9;
            for (int h = 0; h <= j; h++)
                r = min(r, V[i][(int)V[i].size() - j + h - 1] - V[i][h] + 1);
            M[i][j] = r;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int h = 0; h <= k - j; h++)
                dp[i][j + h] = min(dp[i][j + h], dp[i - 1][j] + M[i][h]);
    cout << dp[n][k];
    return (0);
}