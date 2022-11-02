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

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n, m;
int f[300][300];
int c[300][300];
map <int, vector <pii> > A;
int curs, curc;
int d[1000][1000];

void print () {
	int l, r;
	l = r = 500;
	d[l][r] = 1;
	int cur = 1;
	while (l > 100 && r < 900) {
		forn (i, r-l+2) {
			cur ++;
			d[l-1][l+i] = cur;
		}
		forn (i, r-l+1) {
			cur ++;
			d[l+i][r+1] = cur;
		}
		forn (i, r-l+2) {
			cur ++;
			d[r+1][r+1-i] = cur;
		}
		forn (i, r-l+3) {
			cur ++;
			d[r+1-i][l-1] = cur;
		}
		l --;
		r ++;
	}
}

pii q[310*300];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &m);
	A.clear ();
	forn (i, n)
		forn (j, m)
			scanf ("%d", &f[i][j]);
	forn (i, n)
		forn (j, m)
			scanf ("%d", &c[i][j]);
	forn (i, n)
		forn (j, m) {
				int x = f[i][j];
				if (!A.count (x))
					A[x] = vector <pii> ();
				A[x].pb (mp (i, j));
			}
	pii s;
	cin >> s.x >> s.y;
	s.x --;
	s.y --;
	print ();
	int h, t;
	h = 0;
	t = 0;
	q[h] = s;
	curs = 0;
	curc = f[s.x][s.y];
	int64 res = 0;
	while (h <= t) {
		pii v = q[h];
		h ++;
		int col = c[v.x][v.y];
		if (curc == col || curc == 0 || col == -1)
			continue;
		vector < pair <int, pii> > tmp;
		tmp.clear ();
		if (A.count (curc)) {
			vector <pii> a = A[curc];
			A.erase (curc);
			tmp.resize (a.size());
			forn (i, tmp.size()) {
				tmp[i].sc = a[i];
				tmp[i].fs = d[a[i].x-v.x+500][a[i].y-v.y+500];
			}
			sort (all (tmp));
			curs += tmp.size();
			forn (i, tmp.size()) {
				t ++;
				q[t] = tmp[i].sc;
			}
		}
		curc = col;
		res += curs;
	}
	cout << res << endl;

	return 0;
}