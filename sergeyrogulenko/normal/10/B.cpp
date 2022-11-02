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
const string task = "B";

template <class T> T sqr (T x) {return x * x;}

int n, k;
int a[99][99];
int xc, yc;

inline int f (int x, int y)
{
    return abs (x - xc) + abs (y - yc);
}

void check (int D)
{
    int bs = inf;
    int bx, byl, byr;
    forn (i, k)
    {
        int cs = 0;
        int cl = D;
        for (int j = 0; j < k; j ++)
        {
            if (cl == 0)
            {
                cl ++;
                cs -= f(i, j-D);
            }
            if (a[i][j] == 0)
            {
                cl --;
                cs += f(i, j);
            }
            else
            {
                cl = D;
                cs = 0;
            }
            if (cl == 0)
            {
                if (cs < bs)
                {
                    bs = cs;
                    bx = i;
                    byr = j;
                    byl = byr - D + 1;
                }
            }
        }
    }
    if (bs == inf)
        printf ("-1\n");
    else
    {
        printf ("%d %d %d\n", bx+1, byl+1, byr+1);
        for (int i = byl; i <= byr; i ++)
            a[bx][i] = 1;
    }
}

int main ()
{
//  freopen ((task + ".in").data(), "r", stdin);
//  freopen ((task + ".out").data(), "w", stdout);
    scanf ("%d%d", &n, &k);
    seta (a, 0);
    xc = (k + 1) / 2 - 1;
    yc = (k + 1) / 2 - 1;
    forn (i, n)
    {
        int x;
        scanf ("%d", &x);
        check (x);
    }

    return 0;
}