#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAXN = 1100;
const int INF = 100000000;

int n, m;
int dist[MAXN][MAXN][4]; //WNES
bool seen[MAXN][MAXN][4];
char map[MAXN][MAXN];
vector <int> q;
vector <int> q2;
int x[4] = {0, -1, 0, 1};
int y[4] = {-1, 0, 1, 0};

void bfs()
{
    q.push_back (1001 * n + m);
    q2.clear();
    seen[n][m][0] = true;
    dist[n][m][0] = 0;
    while (true)
    {
        for (int i = 0; i < q.size(); i++)
        {
            int r, c, dir;
            dir = q[i] / 1002001;
            r = (q[i] / 1001) % 1001;
            c = q[i] % 1001;
            if ((map[r+x[dir]][c+y[dir]] != 'x') && !seen[r+x[dir]][c+y[dir]][dir])
            {
                seen[r+x[dir]][c+y[dir]][dir] = true;
                dist[r+x[dir]][c+y[dir]][dir] = dist[r][c][dir];
                q.push_back (1002001 * dir + 1001 * (r+x[dir]) + (c+y[dir]));
            }
            if (map[r][c] == '#')
            {
                for (int i = 0; i < 4; i++)
                    if (!seen[r][c][i])
                    {
                        //seen[r][c][i] = true;
                        dist[r][c][i] = dist[r][c][dir] + 1;
                        q2.push_back (1002001 * i + 1001 * r + c);
                    }
            }
        }
        q.clear();
        for (int i = 0; i < q2.size(); i++)
        {
            if (!seen[(q2[i] / 1001) % 1001][q2[i] % 1001][q2[i] / 1002001])
            {
                seen[(q2[i] / 1001) % 1001][q2[i] % 1001][q2[i] / 1002001] = true;
                q.push_back (q2[i]);
            }
        }
        q2.clear();
        if (q.size() == 0)
            break;
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
        {
            map[i][j] = 'x';
            for (int k = 0; k < 4; k++)
            {
                dist[i][j][k] = INF;
                seen[i][j][k] = false;
            }
        }
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    bfs();
    if (dist[1][1][0] == INF)
    {
        cout << "-1\n";
        return 0;
    }
    cout << dist[1][1][0] << "\n";
    //system ("Pause");
    return 0;
}