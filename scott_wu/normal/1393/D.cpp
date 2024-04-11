#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 4010;

int N, M;
short board[MAXN][MAXN];
int bm[MAXN][MAXN];
int bv[MAXN][MAXN];
int bh[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            char c; cin >> c;
            board[i+j][i+M-1-j] = (c - 'a' + 1);
        }

    ll ans = 0;
    for (int i = N + M; i >= 0; i--)
    {
        for (int j = N + M; j >= 0; j--)
        {
            if (board[i][j] == 0)
            {
                bm[i][j] = bv[i][j] = bh[i][j] = 0;
            }
            else
            {
                bv[i][j] = bh[i][j] = 1;
                if (board[i][j] == board[i+2][j])
                    bv[i][j] = bv[i+2][j] + 1;
                if (board[i][j] == board[i][j+2])
                    bh[i][j] = bh[i][j+2] + 1;
                bm[i][j] = 1;
                if (board[i][j] == board[i+1][j+1])
                    bm[i][j] = min (2 * bv[i][j], min (2 * bh[i][j], bm[i+1][j+1] + 1));
                ans += (bm[i][j] + 1) / 2;
            }
        }
    }
    cout << ans << "\n";
}