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
const string task = "d";

template <class T> T sqr (T x) {return x * x;}

int n, m;
int64 res, ans;
int d[15][15], deg[15];

void answer (int64 x)
{
    cout << x << endl;
    exit (0);
}

void go (int64 res, int mask)
{
    if (mask == 0)
    {
        ans = min (ans, res);
        return;
    }
    forn (i, n)
        if (mask & (1 << i))
        {
            for (int j = i+1; j < n; j ++)
                if (mask & (1 << j))
                    go (res + d[i][j], mask ^ (1 << i) ^ (1 << j));
            return;
        }
}

int main ()
{
//  freopen ((task + ".in").data(), "r", stdin);
//  freopen ((task + ".out").data(), "w", stdout);
    scanf ("%d%d", &n, &m);
    res = 0;
    forn (i, n)
        forn (j, n)
            d[i][j] = inf;
    forn (i, n)
        d[i][i] = 0;
    seta (deg, 0);
    forn (i, m)
    {
        int x, y, w;
        scanf ("%d%d%d", &x, &y, &w);
        x --;
        y --;
        deg[x] ++;
        deg[y] ++;
        res += w;
        d[x][y] = d[y][x] = min (d[x][y], w);
    }
    forn (k, n)
        forn (i, n)
            forn (j, n)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    forn (i, n)
        if (deg[i] && d[0][i] >= inf)
            answer (-1);
    int mask = 0;
    forn (i, n)
        if (deg[i] & 1)
            mask |= 1 << i;
    ans = inf64;
    go (res, mask);
    answer (ans);
    return 0;
}