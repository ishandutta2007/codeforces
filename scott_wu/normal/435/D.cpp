#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
int board[MAXN][MAXN];
int rps[MAXN][MAXN];
int cps[MAXN][MAXN];
int dps[MAXN][MAXN];
int eps[MAXN][MAXN];

int xc[4] = {-1, 0, 1, 0};
int yc[4] = {0, -1, 0, 1};

int xdc[4] = {-1, -1, 1, 1};
int ydc[4] = {-1, 1, 1, -1};

bool clean (int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        return cps[x1][min(y1, y2)] == cps[x1][max(y1, y2) + 1];
    }
    if (y1 == y2)
    {
        return rps[min(x1, x2)][y1] == rps[max(x1, x2) + 1][y1];
    }

    if (x1 > x2)
    {
        swap (x1, x2);
        swap (y1, y2);
    }

    if (y1 < y2)
        return dps[x2+1][y2+1] == dps[x1][y1];
    return eps[x2][y2] == eps[x1][y1];

    while (x1 != x2)
    {
        if (board[x1][y1]) return false;
        if (x1 < x2) x1++;
        else x1--;
        if (y1 < y2) y1++;
        else y1--;
    }
    if (board[x1][y1]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {

            char c; cin >> c;
            board[i][j] = c - '0';
            rps[i+1][j] = rps[i][j] + board[i][j];
            cps[i][j+1] = cps[i][j] + board[i][j];
            dps[i+1][j+1] = dps[i][j] + board[i][j];
            if (j)
                eps[i+1][j-1] = eps[i][j] + board[i][j];
        }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (board[i][j]) continue;
            for (int d = 0; d < 4; d++)
            {
                int i1 = i, j1 = j, i2 = i, j2 = j;
                while (true)
                {
                    i1 += xc[d];
                    j1 += yc[d];
                    i2 += xc[(d+1)%4];
                    j2 += yc[(d+1)%4];

                    if (i1 < 0 || i1 >= N || i2 < 0 || i2 >= N)
                        break;
                    if (j1 < 0 || j1 >= M || j2 < 0 || j2 >= M)
                        break;
                    if (board[i1][j1] || board[i2][j2])
                        break;
                    if (clean (i1, j1, i2, j2))
                        ans++;
                }
            }
            for (int d = 0; d < 4; d++)
            {
                int i1 = i, j1 = j, i2 = i, j2 = j;
                while (true)
                {
                    i1 += xdc[d];
                    j1 += ydc[d];
                    i2 += xdc[(d+1)%4];
                    j2 += ydc[(d+1)%4];

                    if (i1 < 0 || i1 >= N || i2 < 0 || i2 >= N)
                        break;
                    if (j1 < 0 || j1 >= M || j2 < 0 || j2 >= M)
                        break;
                    if (board[i1][j1] || board[i2][j2])
                        break;
                    if (clean (i1, j1, i2, j2))
                        ans++;
                }
            }
        }
    cout << ans << "\n";
}