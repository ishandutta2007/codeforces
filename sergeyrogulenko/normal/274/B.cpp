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

int n;
vector<int> g[100500];
int64 l[100500], r[100500];
int64 s[100500];

void go(int v, int p) {
	int64 lf;
	int64 rg;
	lf = rg = 0;
	forn(i, g[v].size())
		if (g[v][i] != p) {
			go(g[v][i], v);
			lf = max(lf, l[g[v][i]]);
			rg = max(rg, r[g[v][i]]);
		}
	s[v] += rg - lf;
	if (s[v] > 0)
		lf += s[v];
	else
		rg -= s[v];
	l[v] = lf;
	r[v] = rg;
}

int main ()
{
	scanf("%d", &n);
	forn(i, n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	forn(i, n) {
		int x;
		scanf("%d", &x);
		s[i] = x;
	}
	go(0, -1);
	cout << l[0] + r[0] << endl;
	return 0;
}