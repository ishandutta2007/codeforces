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

char a[2][200500];
int n, k;
int d[2][200500];
set <pair <int, pii> > S;

void update (pii v, int d1) {
	if (v.sc <= d1)
		return;
	if (v.sc <= n && a[v.fs][v.sc-1] == 'X')
		return;
	if (d[v.fs][v.sc] > d1) {
		S.erase (mp (d[v.fs][v.sc], v));
		d[v.fs][v.sc] = d1;
		S.insert (mp (d[v.fs][v.sc], v));
	}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> k;
	forn (i, 2)
		scanf ("%s", a[i]);
	forn (i, 2)
		forn (j, 200500)
			d[i][j] = inf;	
	d[0][1] = 0;
	S.insert (mp (0, mp (0, 1)));
	while (S.size() > 0) {
		pii v = S.begin()->sc;
		S.erase (S.begin());
		if (v.sc > n) {
			cout << "YES\n";
			return 0;
		}
		pii w = mp (v.fs, v.sc + 1);
		update (w, d[v.fs][v.sc] + 1);
	        w = mp (v.fs, v.sc - 1);
		update (w, d[v.fs][v.sc] + 1);
		w = mp (v.fs^1, v.sc+k);
		update (w, d[v.fs][v.sc] + 1);
	}	
	cout << "NO" << endl;
	return 0;
}