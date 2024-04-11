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
#define x first
#define y second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;
typedef pair <double, double> point;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
double h, f;
vector < vector <point> > A;

double operator * (point p1, point p2) {
	return p1.fs * p2.sc - p1.sc * p2.fs;
}

double S (vector <point> &A) {
	double res = 0;
	forn (i, A.size())
		res += A[i] * (A[(i+1)%A.size()]);
	res = abs (res) / 2.;
	return res;
}

double sgn (double x) {
	if (x > eps)
		return 1;
	else
	if (x < -eps)
		return -1;
	return 0;
}

vector <point> isect (vector <point> A, point p1, point p2, point P) {
	double a = p1.y - p2.y;
	double b = p2.x - p1.x;
	double c = - a * p1.x - b * p1.y;
	int W = sgn (P.x * a + P.y * b + c);
	vector <point> res;
	forn (i, A.size()) {
		if (sgn (A[i].x * a + A[i].y * b + c) * W >= 0)
			res.pb (A[i]);
		int next = (i + 1) % A.size();
		if (sgn (A[i].x * a + A[i].y * b + c) * sgn (A[next].x * a + A[next].y * b + c) < 0) {
			double a1 = A[i].y - A[next].y;
			double b1 = A[next].x - A[i].x;
			double c1 = -a1 * A[i].x - b1 * A[i].y;
			double d =  a * b1 - b * a1;
			double dx = b * c1 - c * b1;
			double dy = c * a1 - a * c1;
			point tmp = mp (dx / d, dy / d);
			res.pb (tmp);
		}
	}
	return res;
}

vector <point> intersect (vector <point> A, vector <point> B) {
	forn (i, B.size())
		A = isect (A, B[i], B[(i+1)%B.size()], B[(i+2) % B.size()]);
	return A;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> h >> f;
	A.resize (n*2);
	forn (i, n) {
		vector <point> tmp;
		double l, r;
		cin >> l >> r;
		tmp.pb (mp (l, -h));
		tmp.pb (mp (r, -h));
		tmp.pb (mp (r / (f-h) * (f+h), h));
		tmp.pb (mp (l / (f-h) * (f+h), h));
		A[i*2] = tmp;
		forn (j, 4)
			tmp[j].sc *= -1.;
		A[i*2+1] = tmp;
	}
	double res = 0;
	forn (i, n*2)
		res += S(A[i]);
	forn (i, n)
		forn (j, n)
			res -= S(intersect (A[i*2], A[j*2+1]));
	printf ("%.10lf\n", res);
	return 0;
}