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

int n;
double len, v1, v2;
double a[305000];
double ans[100500];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> len >> v1 >> v2;
	forn (i, n)
		scanf ("%lf", &a[i]);
	forn (i, n) {
		a[i+n] = a[i] + 2 * len;
		a[i+n+n] = a[i+n] + 2 * len;
	}
	double d = len * v2 / (v1 + v2);
	seta (ans, 0);
	int i = 0;
	int pos = 0;
	double l = a[0];
	double r = d+l;
	while (l < len*2+a[0]) {
		while (a[pos+1] - r < eps)
			pos ++;
		double ds = min (a[i+1] - l, a[pos+1] - r);
		ans[pos-i] += ds / 2. / len;
		l += ds;
		r += ds;
		while (a[i+1] - l < eps)
			i ++;
	}
	forn (i, n+1)
		printf ("%.10lf\n", ans[i]);
	return 0;
}