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

int n, l, k;
double t[201][201][401];
double p[201];
int f[201];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta (t, 0);
	cin >> n >> l >> k;	
	forn (i, n) 
		cin >> p[i];
	forn (i, n)
		p[i] /= 100.;
	forn (i, n)
		cin >> f[i];
	t[0][0][200+min (k, n)] = 1;
	forn (i, n)
		for (int j = 0; j <= i; j ++)
			for (int w = 200-n; w <= 200+n; w ++) {
				t[i+1][j][w] += t[i][j][w] * (1 - p[i]);
				if (f[i] == -1 && w > 0)
					t[i+1][j+1][w-1] += t[i][j][w] * p[i];
				if (f[i] >= 0)
					t[i+1][j+1][min (w+f[i], 200+n)] += t[i][j][w] * p[i];
			}
	vector <double> res;
	for (int j = l; j <= n; j ++)
		for (int w = 200; w <= 200+n; w ++)
			res.pb (t[n][j][w]);
	sort (all (res));
	double ans = 0;
	forn (i, res.size())
		ans += res[i];
	printf ("%.10lf\n", ans);
	return 0;
}