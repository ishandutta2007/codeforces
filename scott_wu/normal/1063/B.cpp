#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N, M;
int board[MAXN][MAXN];
int cd[MAXN][MAXN]; // distance in ft;
int X, Y;
int sx, sy;

vector <pair <int, int> > q[2];

int xc[4] = {-1, 1, 0, 0};
int yc[4] = {0, 0, -1, 1};

void bfs()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cd[i][j] = 1e9;
    cd[sx][sy] = 0;
    q[0].push_back(make_pair (sx, sy));

    while (true)
    {
        if (!q[0].size()) break;
        for (int i = 0; i < q[0].size(); i++)
        {
            int cx = q[0][i].first, cy = q[0][i].second;
            for (int j = 0; j < 4; j++)
            {
                int nx = cx + xc[j], ny = cy + yc[j];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (board[nx][ny]) continue;
                if (j < 3)
                {
                    if (cd[nx][ny] > cd[cx][cy])
                    {
                        cd[nx][ny] = cd[cx][cy];
                        q[0].push_back(make_pair (nx, ny));
                    }
                }
                else
                {
                    if (cd[nx][ny] > cd[cx][cy] + 1)
                    {
                        cd[nx][ny] = cd[cx][cy] + 1;
                        q[1].push_back(make_pair (nx, ny));
                    }
                }
            }
        }
        q[0].clear();
        for (int i = 0; i < q[1].size(); i++)
            q[0].push_back(q[1][i]);
        q[1].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> sx >> sy >> X >> Y;
    sx--, sy--;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }

    bfs ();

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (cd[i][j] > 5e8) continue;
            int rc = cd[i][j];
            int lc = sy - j + rc;
            if (lc <= X && rc <= Y)
                ans++;
        }
    }
    cout << ans << "\n";
}