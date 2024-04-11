#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 1010;

int N, M, i, j;

struct BIBIT
{
    i64 V[MAXN][MAXN];
    void init()
    {
        int i, j;
        fortodo(i, 1, N)
            fortodo(j, 1, N)
                V[i][j] = 0;
    }
    void att(int x0, int y0, i64 v)
    {
        for (int x = x0; x <= N; x += x & (-x))
            for (int y = y0; y <= N; y += y & (-y))
                V[x][y] ^= v;
    }
    i64 qry(int x0, int y0)
    {
        i64 ret = 0;
        for (int x = x0; x; x -= x & (-x))
            for (int y = y0; y; y -= y & (-y))
                ret ^= V[x][y];
        return ret;
    }
};

BIBIT Sxy, Sx, Sy, S;

void Insert(int x, int y, i64 v)
{
    int rx = N - x + 1, ry = N - y + 1;
    if ((rx & 1) && (ry & 1))
        Sxy.att(x, y, v);
    if (rx & 1) Sx.att(x, y, v);
    if (ry & 1) Sy.att(x, y, v);
    S.att(x, y, v);
}

i64 prefix(int x0, int y0)
{
    int rx = N - x0, ry = N - y0;
    i64 ret = 0;
    if ((rx & 1) && (ry & 1)) ret ^= S.qry(x0, y0);
    if (rx & 1) ret ^= Sy.qry(x0, y0);
    if (ry & 1) ret ^= Sx.qry(x0, y0);
    ret ^= Sxy.qry(x0, y0);
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    Sxy.init(); Sx.init(); Sy.init(); S.init();
    int Opt, x1, y1, x2, y2;
    i64 p;
    fortodo(i, 1, M)
        {
            scanf("%d%d%d%d%d", &Opt, &x1, &y1, &x2, &y2);
            if (Opt == 2)
                {
                    scanf("%I64d", &p);
                    Insert(x1, y1, p);
                    Insert(x1, y2 + 1, p);
                    Insert(x2 + 1, y1, p);
                    Insert(x2 + 1, y2 + 1, p);
                }
            else
                printf("%I64d\n", prefix(x2, y2) ^ prefix(x1 - 1, y2) ^ prefix(x2, y1 - 1) ^ prefix(x1 - 1, y1 - 1));
        }
}