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
#include <bitset>
#include <sstream>
#include <queue>

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
typedef pair <double, double> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 1700;

#define fs first
#define sc second

int n;
pii a[nmax];

double dist(pii a, pii b) {
	return sqrt(sqr(a.fs - b.fs) + sqr(a.sc - b.sc));
}

double calc(pii a, pii b, pii c) {
	pii e (b.fs - a.fs, b.sc - a.sc);
	pii w (c.fs - a.fs, c.sc - a.sc);
	return e.fs * w.sc - e.sc * w.fs;
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n;
	forn(i, n)
		cin >> a[i].fs >> a[i].sc;
	a[n]  = a[0];
	a[n + 1] = a[1];


	double res = 1e12;
	for (int i = 0; i < n; i ++) {
		res = min(res, fabs(calc(a[i], a[i+1], a[i+2])) / dist(a[i], a[i+2]) / 2.0);
		// cout << fabs(calc(a[i], a[i+1], a[i+2])) << " " << dist(a[i], a[i+2]) << endl;
		// cout << fabs(calc(a[i], a[i+1], a[i+2])) / dist(a[i], a[i+2]) / 2.0 << endl;
	}
	printf("%0.9lf\n", res);

	return 0;
}