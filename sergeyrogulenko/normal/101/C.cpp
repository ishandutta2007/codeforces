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
#define x first
#define y second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int64, int64> pii64;
typedef long double ldb;
typedef pair <long double, long double> point;

const long double eps = 1e-10;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

pii64 A, B, C;

pii64 operator - (pii64 p1, pii64 p2) {
	return pii64 (p1.x - p2.x, p1.y - p2.y);
}

pii64 rotate (pii64 x) {
	return pii64 (-x.y, x.x);
}

point rotate (point p, long double ang) {
	return point (p.x * cosl (ang) - p.y * sinl (ang), p.x * sinl (ang) + p.y * cosl (ang));
}

bool integer (long double x) {
	long double X = floorl (x + 0.1);
	if (fabsl (x - X) < eps)
		return 1;
	return 0;
}

bool check (pii64 A, pii64 B) {
	if (B == pii64 (0, 0))
		return 1;
	if (A == pii64 (0, 0))
		return 0;
	point a = point (A.x, A.y);
	long double ang = atan2l (a.y, a.x);
	long double d = sqrtl ((long double)(A.x * A.x + A.y * A.y));
	point b = rotate (point (B.x, B.y), -ang);
	b.x /= d;
	b.y /= d;
	b.x = fabsl (b.x);
	b.y = fabsl (b.y);
	if (integer (b.x) && integer (b.y))
		return 1;
	return 0;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	forn (i, 4) {
		pii64 D = B - A;
		if (check (C, D)) {
			cout << "YES\n";
			return 0;
		}
		A = rotate (A);
	}
	cout << "NO\n";
	return 0;
}