#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M, T;
string grid[MAXN];
int cdist[MAXN][MAXN];

vector <pair <int, int> > q;

int xc[4] = {1, -1, 0, 0};
int yc[4] = {0, 0, 1, -1};

bool valid (int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cdist[i][j] = 1e7;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            bool found = false;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + xc[k];
                int ny = j + yc[k];
                if (valid (nx, ny) && grid[nx][ny] == grid[i][j])
                    found = true;
            }
            if (found)
            {
                cdist[i][j] = 0;
                q.push_back(make_pair (i, j));
            }
        }

    for (int nq = 0; nq < q.size(); nq++)
    {
        int x = q[nq].first, y = q[nq].second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + xc[i], ny = y + yc[i];
            if (!valid (nx, ny)) continue;
            if (cdist[nx][ny] > cdist[x][y] + 1)
            {
                cdist[nx][ny] = cdist[x][y] + 1;
                q.push_back (make_pair (nx, ny));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> T;
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    bfs();

    for (int i = 0; i < T; i++)
    {
        int a, b;
        ll t;
        cin >> a >> b >> t;
        a--, b--;
        if (cdist[a][b] >= min (t, (ll) MAXN * MAXN))
        {
            cout << grid[a][b] << "\n";
        }
        else
        {
            if ((cdist[a][b] + t) % 2 == 0)
                cout << grid[a][b] << "\n";
            else
                cout << (char) ('0' + '1' - grid[a][b]) << "\n";
        }
    }
}