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
#define y1 bkbglkmf

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

const int nmax = 100100;

int n, m, k;
int a[nmax], b[nmax], c[nmax];
int r[nmax];

int main ()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;
    forn(i, m)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    forn(i, k)
        scanf("%d", &r[i]);
    long long res = 0;
    forn(i, m)
        forn(j, k)
            if (r[j] >= a[i] && r[j] <= b[i])
                res += r[j] - a[i] + c[i];
    cout << res << endl;
        

    return 0;
}