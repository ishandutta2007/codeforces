#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 12;
int n, A[N][N];
bool M[N][N][N * N][3];
pair < int , int > rev[N], dp[N][N][N * N][3];
priority_queue < pair < pair < int , int > , pair < pair < int , int > , pair < int , int > > > > qu;
inline void Relax(int a, int b, int c, int t, pair < int , int > d)
{
    if (dp[a][b][c][t] > d)
        dp[a][b][c][t] = d, qu.push({{-d.x, -d.y}, {{a, b}, {c, t}}});
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &A[i][j]), rev[A[i][j]] = {i, j};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int h = 0; h < N * N; h ++)
                for (int k = 0; k < 3; k++)
                    dp[i][j][h][k] = {1e9, 1e9};
    Relax(rev[1].x, rev[1].y, 2, 0, {0, 0});
    Relax(rev[1].x, rev[1].y, 2, 1, {0, 0});
    Relax(rev[1].x, rev[1].y, 2, 2, {0, 0});
    while (qu.size())
    {
        auto X = qu.top(); qu.pop();
        int a = X.y.x.x, b = X.y.x.y, c = X.y.y.x, t = X.y.y.y;
        if (M[a][b][c][t]) continue;
        M[a][b][c][t] = 1;
        pair < int , int > d = dp[a][b][c][t];
        if (A[a][b] == c)
        {
            if (c == n * n) return !printf("%d %d\n", dp[a][b][c][t].x, dp[a][b][c][t].y);
            if (dp[a][b][c + 1][t] > dp[a][b][c][t])
                dp[a][b][c + 1][t] = dp[a][b][c][t], qu.push({{-d.x, -d.y}, {{a, b}, {c + 1, t}}});
        }
        for (int i = 0; i < 3; i++)
            Relax(a, b, c, i, {d.x + 1, d.y + 1});
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (t == 0)
                {
                    if (i == a || j == b)
                        Relax(i, j, c, t, {d.x + 1, d.y});
                }
                if (t == 1)
                {
                    if (abs(a - i) == abs(b - j))
                        Relax(i, j, c, t, {d.x + 1, d.y});
                }
                if (t == 2)
                {
                    if (abs(a - i) == 2 && abs(b - j) == 1)
                        Relax(i, j, c, t, {d.x + 1, d.y});
                    if (abs(a - i) == 1 && abs(b - j) == 2)
                        Relax(i, j, c, t, {d.x + 1, d.y});
                }
            }
    }
    return (0);
}