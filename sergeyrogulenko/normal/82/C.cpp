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

int n;
vector < vector <pii> > A;
int p[5000], c[5000], curc[5000];
vector <pii> d;
int loc[5000];
int ans[5000];

void go (int v, int par) {
	forn (i, A[v].size())
		if (A[v][i].fs != par) {
			p[A[v][i].fs] = v;
			c[A[v][i].fs] = A[v][i].sc;
			go (A[v][i].fs, v);
		}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	seta (c, 0);
	d.resize (n);
	A.resize (n);
	forn (i, n) {
		d[i].sc = i;
		scanf ("%d", &d[i].fs);
	}
	sort (all (d));
	forn (i, n)
		loc[i] = i;
	forn (i, n-1) {
		int x, y, w;
		scanf ("%d%d%d", &x, &y, &w);
		x --;
		y --;
		A[x].pb (mp (y, w));
		A[y].pb (mp (x, w));
	}
	go (0, -1);
	forn (i, n)
		ans[i] = inf;
	ans[0] = 0;
	int iter = 0;
	while (1) {
		iter ++;
		bool ok = 1;
		forn (i, n)
			if (loc[i] != 0)
				ok = 0;
		if (ok)
			break;
		forn (i, n)
			curc[i] = c[i];
		forn (i, n) {
			int v = d[i].sc;
			if (loc[v] != 0 && curc[loc[v]] > 0) {
				curc[loc[v]] --;
				loc[v] = p[loc[v]];
				if (loc[v] == 0)
					ans[v] = iter;
			}
		}
	}
	forn (i, n)
		cout << ans[i] << " " ;
	cout << endl;
	return 0;
}