#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 30;

int N;
ll board[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i % 2 == 0)
                board[i][j] = 0;
            else
                board[i][j] = 1LL << (i + j);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j) cout << " ";
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << flush;

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        ll r; cin >> r;

        int cx = 0, cy = 0;
        cout << "1 1\n";
        while (cx < N - 1 || cy < N - 1)
        {
            if (cx == N - 1) cy++;
            else if (cy == N - 1) cx++;
            else
            {
                if ((r ^ board[cx+1][cy]) < (r ^ board[cx][cy+1]))
                    cx++;
                else
                    cy++;
            }
            cout << cx + 1 << " " << cy + 1 << "\n";
        }
        cout << flush;
    }
}