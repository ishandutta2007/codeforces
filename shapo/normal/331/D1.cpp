#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;

#define maxn 300
#define mp make_pair
#define y1 aofhlskny1

#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int cur[maxn][maxn];
int dir[maxn][maxn];
pair< pair< int, int >, int > pos[maxn][maxn][4][50];
const int DX[4] = {0, 1, 0, -1};
const int DY[4] = {1, 0, -1, 0};
int x1, x2, y1, y2;
int q, x, y;
long long t;
int n, b;

int dirV(int dx, int dy)
{
    if (dx == 0)
    {
        if (dy > 0)
            return 0;
        return 2;
    }
    if (dx > 0)
        return 1;
    return 3;
}

int dirC(char c)
{
    if (c == 'U')
        return 0;
    if (c == 'D')
        return 2;
    if (c == 'L')
        return 3;
    return 1;
}

bool notOk(int x, int y)
{
    return (x < 0 || y < 0 || x > b || y > b);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &b);
    memset(dir, -1, sizeof(dir));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int cdir = dirV(x2 - x1, y2 - y1);
        int cx = x1, cy = y1;
        while (cx != x2 || cy != y2)
        {
			//fprintf(stderr, "[%d, %d] -> [%d, %d] -> [%d, %d]\n", x1, y1, cx, cy, x2, y2);
            dir[cx][cy] = cdir;
            cx += DX[cdir], cy += DY[cdir];
        }
        dir[cx][cy] = cdir;
    }
    for (int i = 0; i <= b; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            if (dir[i][j] == -1)
            {
                for (int d = 0; d < 4; ++d)
                {
                    int cx = i + DX[d], cy = j + DY[d];
                    pos[i][j][d][0] = mp(mp(cx, cy), d);
                }
            }
            else
            {
                for (int d = 0; d < 4; ++d)
                {
                    int cx = i + DX[dir[i][j]], cy = j + DY[dir[i][j]];
                    pos[i][j][d][0] = mp(mp(cx, cy), dir[i][j]);
                }
            }
        }
    }
    for (int k = 1; k < 50; ++k)
    {
        for (int i = 0; i <= b; ++i)
        {
            for (int j = 0; j <= b; ++j)
            {
                for (int d = 0; d < 4; ++d)
                {
                    pair< pair< int, int >, int > cur = pos[i][j][d][k - 1];
                    if (notOk(cur.first.first, cur.first.second))
                    {
                        pos[i][j][d][k] = cur;
                    }
                    else
                    {
                        pos[i][j][d][k] = pos[cur.first.first][cur.first.second][cur.second][k - 1];
                    }
                }
            }
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        int dr;
        char cd;
        scanf("%d%d %c" LLD, &x, &y, &cd, &t);
        dr = dirC(cd);
        for (int it = 49; it >= 0; --it)
        {
            if ((1LL << it) <= t)
            {
                t -= (1LL << it);
                pair< pair< int, int >, int > cur = pos[x][y][dr][it];
                x = cur.first.first;
                y = cur.first.second;
                dr = cur.second;
                if (notOk(x, y))
                {
                    if (x < 0) ++x;
                    if (y < 0) ++y;
                    if (x > b) --x;
                    if (y > b) --y;
                    break;
                }
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}