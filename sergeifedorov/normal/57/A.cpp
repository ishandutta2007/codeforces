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

int n, x1, x2, y1, y2;

int calc(int x, int y){
    if (y == 0) return x;
    if (y == n) return 3 * n - x;
    if (x == 0) return 4 * n - y;
    if (x == n) return n + y;
    assert(0);
}

int main ()
{
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int v = calc(x1, y1);
    int u = calc(x2, y2);
    int res = min(abs(v - u), min(v, u) + 4 * n - max(v, u));
    cout << res << endl;

    return 0;
}