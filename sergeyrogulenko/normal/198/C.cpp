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

long double xp, yp, vp, R;
long double x, y, v, r;

long double dist (long double x1, long double y1, long double x2, long double y2) {
	return sqrt (sqr (x1 - x2) + sqr (y1 - y2));
}

long double prod (long double x1, long double y1, long double x2, long double y2) {
	return x1 * x2 + y1 * y2;
}

long double len (long double x, long double y) {
	return dist (x, y, 0, 0);
}

long double get_ang (long double x1, long double y1, long double x2, long double y2) {
	return acos (prod (x1, y1, x2, y2)/len(x1,y1)/len(x2,y2));
}

bool check (long double t) {
	long double ang0 = t * vp / R;
	long double cx = xp * cos (ang0) - yp * sin (ang0);
	long double cy = xp * sin (ang0) + yp * cos (ang0);
	if (dist (cx, cy, x, y) < eps)
		return 1;
	bool per = 0;
	long double A = y - cy;
	long double B = cx - x;
	long double C = - A * x - B * y;
	if (fabs (C) / sqrt (A * A + B * B) < r) 
		if (prod (0 - cx, 0 - cy, x - cx, y - cy) > 0 &&
			prod (0 - x, 0 - y, cx - x, cy - y) > 0)
			per = 1;
	if (!per)
		return dist (x, y, cx, cy) < t * v;
	long double d = sqrt ((dist (0, 0, x, y) - r) * (dist (0, 0, x, y) + r));
	long double cd = sqrt ((dist (0, 0, cx, cy) - r) * (dist (0, 0, cx, cy) + r));
	long double ang = pi - get_ang (0-cx, 0-cy, x-cx, y-cy) - get_ang (0-x, 0-y, cx-x, cy-y);
	long double ang1 = acos (r / len (x, y));
	long double ang2 = acos (r / len (cx, cy));
	ang -= ang1 + ang2;
	long double D = d + cd + r * ang;
	return D < t * v;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> xp >> yp >> vp;
	cin >> x >> y >> v >> r;
	R = sqrt (xp * xp + yp * yp);
	long double l = 0;
	long double r = 1e9;
	forn (i, 200) {
		long double m = (l + r) / 2.;
		if (check (m))
			r = m;
		else
			l = m;
	}
	l = (l + r) / 2.;
	cout.precision (12);
	cout << fixed << l << endl;
	return 0;
}