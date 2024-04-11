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
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n, k;
int T[4101][4101];
int t[10101];
int d[10101];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &k);
	forn (i, n)
		scanf ("%d%d", &t[i+1], &d[i+1]);
	for (int i = n+1; i <= n + 5000; i ++)
		t[i] = 86401;
	forn (i, n+1)
		forn (j, k+1)
			T[i][j] = inf;
	for (int i = 0; i <= k; i ++)
		T[0][i] = 0;
	int res = 0;
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= k; j ++) {
			T[i+1][j] = min (T[i+1][j], max (T[i][j] + 1, t[i+1]) + d[i+1] - 1);
			T[i+1][j+1] = min (T[i+1][j+1], T[i][j]);
			res = max (res, t[i+1+k-j] - T[i][j] - 1);
		}
	cout << res << endl;
	return 0;
}