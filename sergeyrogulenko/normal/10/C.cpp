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
const string task = "C";

template <class T> T sqr (T x) {return x * x;}

int s[10];
int64 t[10];
int d[1000001], sd[1000001], deg[1000001];

int f (int x)
{
    if (x <= 9)
        return x;
    int res = 0;
    while (x > 0)
    {
        res += x % 10;
        x /= 10;
    }
    return f (res);
}

int main ()
{
//  freopen ((task + ".in").data(), "r", stdin);
//  freopen ((task + ".out").data(), "w", stdout);
    int n;
    cin >> n;
    int64 res = 0;
    seta (s, 0);
    for (int i = 1; i <= n; i ++)
        s[f(i)] ++;
    seta (t, 0);
    forn (y, 10)
        forn (i1, 10)
            forn (j1, 10)
                if (f(i1*j1) == y)
                    t[y] += (int64)(s[i1]) * (int64)(s[j1]);
    seta (d, 255);
    d[1] = 1;
    for (int i = 2; i <= n; i ++)
        if (d[i] == -1)
        {
            d[i] = i;
            int x = i + i;
            while (x <= n)
            {
                d[x] = i;
                x += i;
            }
        }
    seta (deg, 0);
    for (int i = 2; i <= n; i ++)
        if (d[i] == d[i/d[i]])
            deg[i] = deg[i/d[i]] + 1;
        else
            deg[i] = 1;
    seta (sd, 0);
    sd[1] = 1;
    for (int i = 2; i <= n; i ++)
        if (d[i] == d[i/d[i]])
            sd[i] = sd[i/d[i]] / (deg[i/d[i]] + 1) * (deg[i]+1);
        else
            sd[i] = sd[i/d[i]] * 2;
    for (int i = 1; i <= n; i ++)
    {
        int ci = sd[i];
        res -= ci;
        res += t[f(i)];
    }
    cout << res << endl;
    return 0;
}