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

char s[3000000], s1[3000000];
int n;

double calc (char *s)
{
    double res = 0;
    int rx = 0;
    forn (i, n)
        if (s[i] != 'X')
            rx ++;
    if (n % 2 == 0)
        res = (double)rx / (n+1) / 2.;
    else
        res = (double)rx / n / 2.;
    int dp = 0;
    int ry = 0;
    int len = 0;
    int i = 0;
    int l1 = 0;
    while (i < n)
    {
        if ((s[i] == 'L' && ((dp+i) & 1) == 1) || (s[i] == 'R' && ((dp+i) & 1) == 0))
            len ++;
        else
        if ((s[i] == 'L' && ((dp+i) & 1) == 0) || (s[i] == 'R' && ((dp+i) & 1) == 1))
        {
            if (len > 1)
            {
                dp ++;
                ry += len;
                len = 0;
                continue;
            }
            else
            if (len == 1)
            {
                l1 ++;
                len = 0;
            }
            ry ++;
        }
        i ++;
    }
    if (len > 1)
    {
        ry += len;
        dp ++;
        len = 0;
    }
    if (((n + dp) & 1) == 1)
    {
        dp ++;
        if (len == 1)
            ry ++;
    }
    else
    if (len == 1)
        l1 ++;
    while (l1 > 0 && dp+n >= ry * 2)
    {
        ry ++;
        l1 --;
        dp += 2;
    }
    res = max (res, (double)ry / (n+dp));
    return res;
}

int main ()
{
//  freopen ("input.txt", "r", stdin);
    scanf ("%s", s1);
    n = strlen (s1);
    int p = 0;
    seta (s, 0);
    s[p++] = s1[0];
    for (int i = 1; i < n; i ++)
    {
        if (s1[i] == s1[i-1] && s1[i] != 'X')
            s[p++] = 'X';
        s[p++] = s1[i];
    }
    double res = 0;
    n = strlen (s);
    if (s[0] == s[n-1] && s[0] != 'X')
    {
        s[n++] = 'X';
        double res1 = calc (s);

        for (int i = n-1; i > 0; i --)
            s[i] = s[i-1];
        s[0] = 'X';
        double res2 = calc (s);
        res = max (res1, res2);
    }
    else
        res = calc (s);
    res = res * 100;
    res = floor (res * 1e6) / 1e6;
    printf ("%.6lf\n", res);
    return 0;
}