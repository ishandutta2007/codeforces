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

const int64 P = 1000000007;

int n, k;
int s1, s2;
int d[51][51][2];
pair<pii, int> q[51*51*20];
int hh, tt;
int64 t[51][51][2];
int64 c[101][101];

void bfs(int v50, int v100, int tp) {
	d[v50][v100][tp] = 0;
	hh = tt = 0;
	q[hh] = mp(mp(v50, v100), tp);
	while (hh <= tt) {
		v50 = q[hh].fs.fs;
		v100 = q[hh].fs.sc;
		tp = q[hh].sc;
		hh++;
		forn(i, v50+1)
			forn(j, v100+1)
				if (i + j > 0 && i * 50 + j * 100 <= k) {
					int w50 = v50 - i;
					int w100 = v100 - j;
					int wt = tp ^ 1;
					w50 = s1 - w50;
					w100 = s2 - w100;
					if (d[w50][w100][wt] == -1) {
						d[w50][w100][wt] = d[v50][v100][tp] + 1;
						tt++;
						q[tt] = mp(mp(w50, w100), wt);
					}
				}
	}

}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> k;
	s1 = s2 = 0;
	forn(i, n) {
		int x;
		cin >> x;
		if (x == 50)
			s1++;
		else
			s2++;
	}
	seta(d, 255);
	bfs(s1, s2, 1);
	int best = d[s1][s2][0];
	if (best == -1) {
		cout << -1 << endl << 0 << endl;
		return 0;
	}
	forn(i, 101)
		c[i][0] = 1;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % P;
	t[s1][s2][1] = 1;
	for (int ii = 1; ii <= tt; ii++) {
		int v1 = q[ii].fs.fs;
		int v2 = q[ii].fs.sc;
		int vt = q[ii].sc;
		forn(i, v1+1)
			forn(j, v2+1)
				if (i + j > 0 && i * 50 + j * 100 <= k) {
					int w1 = v1 - i;
					int w2 = v2 - j;
					int wt = vt ^ 1;
					w1 = s1 - w1;
					w2 = s2 - w2;
					if (d[v1][v2][vt] == d[w1][w2][wt] + 1)
						t[v1][v2][vt] = (t[v1][v2][vt] + c[v1][i] * c[v2][j] % P * t[w1][w2][wt]) % P;
				}		
	}
	cout << best << endl;
	cout << t[s1][s2][0] << endl;
	return 0;
}