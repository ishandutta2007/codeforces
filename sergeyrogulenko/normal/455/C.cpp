#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n, m, k;
int l[300500];
int d[300500];
vector<int> g[300500];

int leader(int x) {
	if (l[x] != x)
		l[x] = leader(l[x]);
	return l[x];
}

void merge(int x, int y) {
	x = leader(x);
	y = leader(y);
	if (x == y) return;
	int rx = (d[x] + 1) / 2;
	int ry = (d[y] + 1) / 2;
	if (rx < ry) {
		swap(x, y);
		swap(rx, ry);
	}
	d[x] = max(d[x], rx + ry + 1);
	l[y] = x;
}

void add(int x, int y) {
	g[x].pb(y);
	g[y].pb(x);
}

bool u[300500];
int dt[300500];
vector<int> q;

void go(int v) {
	if (u[v]) return;
	u[v] = 1;
	forn(i, g[v].size()) {
		int w = g[v][i];
		if (!u[w]) {
			dt[w] = dt[v] + 1;
			go(w);
		}
	}
	q.pb(v);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m >> k;
	forn(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		add(x, y);
	}
	seta(u, 0);
	forn(i, n)
		if (!u[i]) {
			q.clear();
			int v = i;
			dt[v] = 0;
			go(v);
			forn(j, q.size()) {
				u[q[j]] = 0;
				if (dt[q[j]] > dt[v]) {
					v = q[j];
				}
				l[q[j]] = i;
			}
			dt[v] = 0;
			go(v);
			int ds = 0;
			forn(j, q.size()) {
				ds = max(ds, dt[q[j]]);				
			}
			d[i] = ds;
		}
	forn(i, k) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int x;
			scanf("%d", &x);
			x--;
			printf("%d\n", d[leader(x)]);
		} else {
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			merge(x, y);
		}
	}
	return 0;
}