#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
char grid[55][55];
bool ok[55][55];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
            ok[i][j] = false;
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (max (i, j) == N - 1 && grid[i][j] == '1')
                ok[i][j] = true;

    bool bad = false;
    for (int i = N - 2; i >= 0; i--)
        for (int j = N - 2; j >= 0; j--)
            if (grid[i][j] == '1')
            {
                if (ok[i+1][j] || ok[i][j+1])
                {
                    ok[i][j] = true;
                }
                else
                    bad = true;
            }
    if (bad) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        gogo();
    }
}