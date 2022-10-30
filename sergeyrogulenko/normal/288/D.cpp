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
int d[100500], par[100500];
int64 s[100500], paths[100500];
int64 t[100500], res;

void go(int v, int p) {
	s[v] = 1;
	par[v] = p;
	if (p != -1)
		d[v] = d[p] + 1;	
	forn(i, g[v].size()) 
		if (g[v][i] != p) {
			int w = g[v][i];
			go(w, v);
			s[v] += s[w];
		}
	
	paths[v] = 0;
	forn(i, g[v].size())
		if (g[v][i] != p) {
			int w = g[v][i];
			paths[v] += s[w] * (s[v] - s[w] - 1);
		}
	paths[v] /= 2;
	paths[v] += s[v] - 1;
	
	t[v] = 0;
	forn(i, g[v].size())
		if (g[v][i] != p) {
			int w = g[v][i];
			t[v] += t[w];
		}

	res -= t[v];
	t[v] += paths[v] * s[v];

	forn(i, g[v].size())
		if (g[v][i] != p) {
			int w = g[v][i];   
			res -= t[w] * (s[v] - s[w] - 1);
		}
}

int u[100];

void paint(int a, int b) {
	while (d[a] > d[b]) {
		u[a]++;
		a = par[a];
	}
	while (d[a] < d[b]) {
		u[b]++;
		b = par[b];
	}
	while (a != b) {
		u[a]++;
		u[b]++;
		a = par[a];
		b = par[b];
	}
	u[a]++;
}

bool check(int a, int b, int c, int d) {
	seta(u, 0);
	paint(a, b);
	paint(c, d);
	forn(i, n)
		if (u[i] > 1)
			return 0;
	return 1;
}

int64 slow() {
	int res = 0;
	forn(b, n)
		forn(a, b)
			forn(d, n)
				ford(c, d)
					if (check(a, b, c, d))
						res++;
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	forn(i, n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	res = 0;
	go(0, -1);
	res *= 2;
	int64 sum = 0;
	forn(i, n)
		sum += paths[i];
	forn(i, n)
		res += paths[i] * (sum - paths[i]);
//	assert(res == slow());
	cout << res << endl;
	return 0;
}