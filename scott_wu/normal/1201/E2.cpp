#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
int WX, WY, BX, BY;

int wdist[MAXN][MAXN];
int wprev[MAXN][MAXN];
int bdist[MAXN][MAXN];
int bprev[MAXN][MAXN];

int xc[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
int yc[8] = {-1, -1, -2, -2, 1, 1, 2, 2};

bool is_white;

void await()
{
    int nx, ny;
    cin >> nx >> ny;

    if (nx == -1)
        exit(0);

    if (is_white)
    {
        BX = nx;
        BY = ny;
    }
    else
    {
        WX = nx;
        WY = ny;
    }
}

void wsolve (int sx, int sy)
{
    wdist[sx][sy] = 0;
    wprev[sx][sy] = -1;
    vector <pair <int, int> > q;
    q.push_back(make_pair (sx, sy));
    for (int i = 0; i < q.size(); i++)
    {
        int cx = q[i].first, cy = q[i].second;
        int cdist = wdist[cx][cy];
        for (int j = 0; j < 8; j++)
        {
            int x = cx + xc[j], y = cy + yc[j];
            if (x < 1 || y < 1 || x > N || y > M) continue;
            if (wdist[x][y] <= cdist + 1) continue;
            wdist[x][y] = cdist + 1;
            wprev[x][y] = j;
            q.push_back(make_pair (x, y));
        }
    }
}

void bsolve (int sx, int sy)
{
    bdist[sx][sy] = 0;
    bprev[sx][sy] = -1;
    vector <pair <int, int> > q;
    q.push_back(make_pair (sx, sy));
    for (int i = 0; i < q.size(); i++)
    {
        int cx = q[i].first, cy = q[i].second;
        int cdist = bdist[cx][cy];
        for (int j = 0; j < 8; j++)
        {
            int x = cx + xc[j], y = cy + yc[j];
            if (x < 1 || y < 1 || x > N || y > M) continue;
            if (bdist[x][y] <= cdist + 1) continue;
            bdist[x][y] = cdist + 1;
            bprev[x][y] = j;
            q.push_back(make_pair (x, y));
        }
    }
}

bool wwin (int bmove)
{
    int wturns = wdist[WX][WY];
    int wblock = bdist[WX][WY];
    int bturns = bdist[BX][BY];
    int bblock = wdist[BX][BY];

    //cout << "loc " << WX << WY << " " << BX << BY << "\n";
    //cout << wturns << " " << bturns << " " << wblock << " " << bblock << "\n";

    if (bmove)
    {
        // black to move
        if (bturns <= wturns)
        {
            if (bturns < wblock)
                return false;
            if (bturns % 2 == wblock % 2)
                return true;
            return false;
        }
        else
        {
            if (wturns < bblock - 1)
                return true;
            if (wturns % 2 != bblock % 2)
                return false;
            return true;
        }
    }
    else
    {

        // white to move
        if (wturns <= bturns)
        {
            if (wturns < bblock)
                return true;
            if (wturns % 2 == bblock % 2)
                return false;
            return true;
        }
        else
        {
            if (bturns < wblock - 1)
                return false;
            if (bturns % 2 != wblock % 2)
                return true;
            return false;
        }
    }
}

int main()
{
    cin >> N >> M >> WX >> WY >> BX >> BY;

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            wdist[i][j] = bdist[i][j] = 1e9;
    wsolve (N/2, M/2);
    bsolve (N/2+1, M/2);

    if (wwin(0))
    {
        is_white = true;
        cout << "WHITE\n";
    }
    else
    {
        is_white = false;
        cout << "BLACK\n";
        await();
    }

    while (true)
    {
        int bloc = -1, bturns = 1e9;
        for (int i = 0; i < 8; i++)
        {
            if (is_white)
            {
                WX += xc[i];
                WY += yc[i];
                if (WX >= 1 && WX <= N && WY >= 1 && WY <= M)
                {
                    if (wwin(1))
                    {
                        if (wdist[WX][WY] < bturns)
                        {
                            bturns = wdist[WX][WY];
                            bloc = i;
                        }
                    }
                }
                WX -= xc[i];
                WY -= yc[i];
            }
            else
            {
                BX += xc[i];
                BY += yc[i];
                if (BX >= 1 && BX <= N && BY >= 1 && BY <= M)
                {
                    if (!wwin(0))
                    {
                        if (bdist[BX][BY] < bturns)
                        {
                            bturns = bdist[BX][BY];
                            bloc = i;
                        }
                    }
                }
                BX -= xc[i];
                BY -= yc[i];
            }
        }

        if (is_white)
        {
            WX += xc[bloc];
            WY += yc[bloc];
            cout << WX << " " << WY << "\n" << flush;
        }
        else
        {
            BX += xc[bloc];
            BY += yc[bloc];
            cout << BX << " " << BY << "\n" << flush;
        }

        if (is_white && WX == N/2 && WY == M/2)
            break;
        if (!is_white && BX == N/2 + 1 && BY == M/2)
            break;

        if (WX == BX && WY == BY)
            break;

        await();
    }
}