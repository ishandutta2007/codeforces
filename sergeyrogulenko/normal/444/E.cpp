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

int n;
vector<pii> g[3050];
bool my[3050];
int s;
int best;
int col[3050];
int w[3050];

pii dfs(int v) {
	pii res;
	res.fs = 1;
	res.sc = w[v];
	forn(i, g[v].size())
		if (my[g[v][i].fs] && col[g[v][i].fs] == -1) {
			col[g[v][i].fs] = col[v];
			pii q = dfs(g[v][i].fs);
			res.fs += q.fs;
			res.sc += q.sc;
		}
	return res;
}

bool split() {
	best = -1;
	int u, v;
	u = v = -1;
	forn(i, n)
		if (my[i]) {
			forn(j, g[i].size())
				if (my[g[i][j].fs] && best < g[i][j].sc) {
					best = g[i][j].sc;
					u = i;
					v = g[i][j].fs;
				}
		}
	forn(i, n)
		col[i] = -1;
	col[u] = 0;
	col[v] = 1;
	pii su = dfs(u);
	pii sv = dfs(v);
	int ccol = 0;
	if (su.fs < sv.fs) {
		swap(su, sv);
		ccol = 1;
	}
	s += sv.sc;
	forn(i, n)
		if (col[i] != ccol)
			my[i] = 0;
	return (su.fs <= s);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	forn(i, n)
		my[i] = 1;
	s = 0;
	forn(i, n-1) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		g[x].pb(mp(y, z));
		g[y].pb(mp(x, z));		
	}
	forn(i, n) {
		scanf("%d", &w[i]);
	}
	while (true) {
		if (split()) {
			cout << best << endl;
			return 0;
		}
	}
	return 0;
}