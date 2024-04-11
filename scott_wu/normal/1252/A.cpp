#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N, M, K;
string board[MAXN];
char ans[MAXN][MAXN];

char gchar (int x)
{
    if (x < 26)
    {
        return ('a' + x);
    }
    else if (x < 52)
    {
        return ('A' + (x - 26));
    }
    else
    {
        return ('0' + (x - 52));
    }
}

void gogo()
{
    cin >> N >> M >> K;
    int ctot = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        for (int j = 0; j < M; j++)
            if (board[i][j] == 'R') ctot++;
    }

    int ct = 0;
    int ck = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int cj = j;
            if (i % 2 == 1) cj = (M - 1 - j);

            ans[i][cj] = gchar (ck);
            if (board[i][cj] == 'R') ct++;
            if (((ck + 1) * ctot) / K <= ct)
            {
                ck = min (K - 1, ck + 1);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << ans[i][j];
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}