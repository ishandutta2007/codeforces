#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2007, ALP = 26;
int n, m, A[N], last[ALP], Next[N][ALP];
pair < int , int > dp[N][N];
vector < int > Nxt[N][ALP];
string t, S[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    for (int i = 0; i < ALP; i++)
        for (int j = 1; j <= n; j++)
            Nxt[j][i].resize((int)S[j].size() + 1);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &A[i]);
    cin >> t;
    for (int i = 1; i <= n; i++)
    {
        fill(last, last + ALP, 2e9);
        for (int j = S[i].size() - 1; j + 1; j--)
        {
            last[S[i][j] - 'a'] = j;
            for (int ch = 0; ch < ALP; ch ++)
                Nxt[i][ch][j] = last[ch];
        }
    }
    for (int ch = 0; ch < ALP; ch ++)
        Next[m][ch] = 2e9;
    for (int i = m - 1; i; i--)
    {
        for (int ch = 0; ch < ALP; ch ++)
        {
            if (Nxt[A[i + 1]][ch][0] != 2e9)
                Next[i][ch] = i + 1;
            else
                Next[i][ch] = Next[i + 1][ch];
        }
    }
    for (int i = 0; i <= t.size(); dp[i][0] = {1, 0}, i++)
        for (int j = 1; j < N; j++)
            dp[i][j] = {m + 1, 2e9};
    for (int i = 1; i <= t.size(); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int ch = t[i - 1] - 'a';
            dp[i][j] = dp[i - 1][j];
            auto X = dp[i - 1][j - 1];
            if (X.x == m + 1) continue;
            if (Nxt[A[X.x]][ch][X.y] != 2e9)
                dp[i][j] = min(dp[i][j], {X.x, Nxt[A[X.x]][ch][X.y] + 1});
            else
            {
                int to = Next[X.x][ch];
                if (to <= m)
                    dp[i][j] = min(dp[i][j], {to, Nxt[A[to]][ch][0] + 1});
            }
            if (dp[i][j].x <= m && dp[i][j].y == S[A[dp[i][j].x]].size())
                dp[i][j] = {dp[i][j].x + 1, 0};
        }
    }
    for (int i = t.size(); i + 1; i--)
        if (dp[t.size()][i].y != 2e9)
            return !printf("%d", i);
}