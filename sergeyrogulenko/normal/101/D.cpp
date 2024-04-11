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
typedef pair <double, double> point;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
vector <pii> g[100000];
double s[100000], t[100000], d[100000];
vector <point> a;

bool less1 (point p1, point p2) {
	return p1.fs * p2.sc < p2.fs * p1.sc;
}

double go (int v, int p) {
	d[v] = 0;
	s[v] = 1;
	t[v] = 0;
	forn (i, g[v].size())
		if (g[v][i].fs != p) {
			int w = g[v][i].fs;
			go (w, v);
			s[v] += s[w];
			d[v] += d[w] + 2 * g[v][i].sc;
		}
	a.clear ();
	forn (i, g[v].size())
		if (g[v][i].fs != p) {
			int w = g[v][i].fs;
			a.pb (mp (d[w]+2*g[v][i].sc, s[w]));
			t[v] += (t[w] + g[v][i].sc) * s[w] / s[v];
		}	
	sort (all (a), less1);
	double sd = 0;
	forn (i, a.size()) {
		t[v] += a[i].sc / s[v] * sd;
		sd += a[i].fs;
	}
	return t[v];
}

int main ()
{
	//freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	forn (i, n) 
		g[i].clear ();
	forn (i, n-1) {
		int x, y, w;
		scanf ("%d%d%d", &x, &y, &w);
		x --;
		y --;
		g[x].pb (mp (y, w));
		g[y].pb (mp (x, w));
	}
	printf ("%.9lf\n", go (0, -1) * n / (n-1));
	return 0;
}