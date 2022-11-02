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

int n, m;
int a[19][19];
int s[524288];
int64 t[524288][19];

int64 calc (int64 st, int64 mask, int64 fn)
{
    seta (t, 0);
    t[mask][fn] = 1;
    int64 res = 0;
    forn (i, 1 << n)
        if (i & mask)
            forn (j, n)
                if (t[i][j] > 0)
                {
                    if (s[i] >= 3 && a[st][j])
                        res += t[i][j];
                    for (int k = st+1; k < n; k ++)
                        if (!(i &(1 << k)) && a[j][k])
                            t[i|(1<<k)][k] += t[i][j];
                }
    return res;
}

int main ()
{
//  freopen ("input.txt", "r", stdin);
    cin >> n >> m;
    seta (a, 0);
    seta (s, 0);
    forn (i, 524288)
        s[i] = s[i>>1] + (i & 1);
    forn (i, m)
    {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        a[x][y] = a[y][x] = 1;
    }
    int64 res = 0;
    forn (i, n)
        res += calc (i, 1 << i, i);
    cout << res / 2 << endl;
    return 0;
}