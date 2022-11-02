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

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

vector <pii> a;
vector <int> x, y;
set<pii> M;
int n, k;

bool less_x (int p1, int p2) {
	return a[p1].fs < a[p2].fs;
}

bool less_y (int p1, int p2) {
	return a[p1].sc < a[p2].sc;
}

set <pii> S;
vector <pii> ans;

bool check (pii mid) {
	int ks = k;
	forn (i, n) {
		pii P = a[i];
		P.fs = 2 * mid.fs - P.fs;
		P.sc = 2 * mid.sc - P.sc;
		set <pii> :: iterator it = M.find (P);
		if (it == M.end()) 
			ks --;
		if (ks < 0)
			return 0;
	}
	return 1;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &k);
	if (n <= k) {
		cout << -1 << endl;
		return 0;
	}
	a.resize (n);
	forn (i, n) {
		scanf ("%d%d", &a[i].fs, &a[i].sc);
		a[i].fs *= 2;
		a[i].sc *= 2;
		M.insert (a[i]);
	}
	sort (all (a));
	x.resize (n);
	forn (i, n)
		x[i] = i;
	y = x;
	sort (all (x), less_x);
	sort (all (y), less_y);
	for (int lx = 0; lx <= k; lx ++)
		for (int ly = 0; ly <= k; ly ++)
			for (int rx = 0; rx <= k; rx ++)
				for (int ry = 0; ry <= k; ry ++) 
					S.insert (mp ((a[x[lx]].fs + a[x[n-1-rx]].fs) / 2, (a[y[ly]].sc + a[y[n-1-ry]].sc) / 2));
	for (set <pii> :: iterator it = S.begin(); it != S.end(); it ++)
		if (check (*it))
			ans.pb (*it);
	printf ("%d\n", ans.size());
	forn (i, ans.size())
		printf ("%.1lf %.1lf\n", (double)ans[i].fs / 2, (double)ans[i].sc / 2);
	return 0;
}