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
const string task = "A";

template <class T> T sqr (T x) {return x * x;}

int l[100], r[100];
int p1, p2, p3, t1, t2, n;

int main ()
{
//  freopen ((task + ".in").data(), "r", stdin);
//  freopen ((task + ".out").data(), "w", stdout);
    scanf ("%d %d%d%d %d%d", &n, &p1, &p2, &p3, &t1, &t2);
    forn (i, n)
        scanf ("%d%d", &l[i], &r[i]);
    int res = 0;
    for (int i = 0; i < n; i ++)
    {
        res += (r[i] - l[i]) * p1;
        if (i + 1 < n)
        {
            int a, b;
            a = r[i];
            b = min (a + t1, l[i+1]);
            res += (b - a) * p1;
            a = b;
            b = min (a + t2, l[i+1]);
            res += (b - a) * p2;
            a = b;
            b = max (a, l[i+1]);
            res += (b - a) * p3;
        }
    }
    cout << res << endl;
    return 0;
}