#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n, m, it;
bool a[250][250];
int u[250][250];
int lx, ly, rx, ry, k;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void go (int vx, int vy)
{
    if (u[vx][vy])
        return;
    u[vx][vy] = it;
    lx = min (lx, vx);
    rx = max (rx, vx);
    ly = min (ly, vy);
    ry = max (ry, vy);
    k ++;
    forn (i, 8)
    {
        int x = vx + dx[i];
        int y = vy + dy[i];
        if (0 <= x && x < n && 0 <= y && y < m)
            if (a[x][y] == 1)
                go (x, y);
    }
}

bool check1 (int x, int y)
{
    if (k < 4)
        return 0;
    if (rx - lx != ry - ly)
        return 0;
    int tmp = 0;
    for (int i = lx; i <= rx; i ++)
    {
        if (!u[i][ly] || !u[i][ry])
            return 0;
        tmp += 2;
    }
    for (int i = ly+1; i <= ry-1; i ++)
    {
        if (!u[lx][i] || !u[rx][i])
            return 0;
        tmp += 2;
    }
    if (tmp == k)
        return 1;
    else
        return 0;
}

bool check2 (int x, int y)
{
    if (k < 4)
        return 0;
    if (rx - lx != ry - ly)
        return 0;
    if (ry - y != y - ly)
        return 0;
    int tmp = 0;
    int x1 = x;
    int y1 = y;
    int x2 = lx + y - ly;
    int y2 = ly;
    for (int i = 0; i <= y - ly; i ++)
    {
        if (!u[x1+i][y1+i] || !u[x2+i][y2+i])
            return 0;
        tmp += 2;
    }
    tmp -= 4;
    x1 = x2;
    y1 = y2;
    x2 = rx;
    y2 = y;
    for (int i = 0; i <= y - ly; i ++)
    {
        if (!u[x1-i][y1+i] || !u[x2-i][y2+i])
            return 0;
        tmp += 2;
    }
    if (tmp == k)
        return 1;
    else
        return 0;
}

void ggogogo ()
{
    scanf ("%d%d", &n, &m);
    forn (i, n)
        forn (j, m)
        {
            char ch;
            scanf (" %c", &ch);
            a[i][j] = ch == '1';
        }
    forn (i, n)
        forn (j, m)
            u[i][j] = 0;
    it = 0;
    int res = 0;
    forn (i, n)
        forn (j, m)
            if (a[i][j] && !u[i][j])
            {
                k = 0;
                it ++;
                lx = rx = i;
                ly = ry = j;
                go (i, j);
                if (check1 (i, j) || check2 (i, j))
                    res ++;
            }
    printf ("%d\n", res);
}

int main ()
{
//  freopen ("input.txt", "r", stdin);
    int tt;
    scanf ("%d", &tt);
    forn (ii, tt)
        ggogogo ();
    return 0;
}