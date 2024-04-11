#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N, M;
string grid[MAXN];
    
void gogo()
{
    cin >> N >> M;

    bool hasA = false, hasP = false;
    int bb = 0;
    int xlo = 1e9, xhi = -1, ylo = 1e9, yhi = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 'A')
            {
                hasA = true;
                int cv = 0;
                if (i == 0 || i == N - 1) cv++;
                if (j == 0 || j == M - 1) cv++;
                bb = max (bb, cv);
            }
            else
            {
                xlo = min (xlo, i);
                xhi = max (xhi, i);
                ylo = min (ylo, j);
                yhi = max (yhi, j);
                hasP = true;
            }
        }
    }

    int ans;
    if (!hasA)
    {
        ans = -1;
    }
    else if (!hasP)
    {
        ans = 0;
    }
    else if (xlo > 0 || xhi < N - 1 || ylo > 0 || yhi < M - 1)
    {
        ans = 1;
    }
    else
        ans = 4 - bb;

    for (int i = 0; i < N; i++)
    {
        bool bad = false;
        for (int j = 0; j < M; j++)
            if (grid[i][j] == 'P')
                bad = true;
        if (!bad) ans = min (ans, 2);
    }
    for (int j = 0; j < M; j++)
    {
        bool bad = false;
        for (int i = 0; i < N; i++)
            if (grid[i][j] == 'P')
                bad = true;
        if (!bad) ans = min (ans, 2);
    }

    if (ans == -1)
        cout << "MORTAL\n";
    else
        cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}