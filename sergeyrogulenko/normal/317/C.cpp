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

int n, m;
int V;
int a[500], b[500];
int l[500];
vector<int> g[500];
bool live[500];
bool u[500];

int leader(int v) {
	if (l[v] != v)
		l[v] = leader(l[v]);
	return l[v];
}

void unite(int v1, int v2) {
	v1 = leader(v1);
	v2 = leader(v2);
	l[v1] = v2;
}

vector<pair<pii, int> > ans;

void push_from(int v, int x) {
	u[v] = 1;
	forn(i, g[v].size()) {
		if (x == 0) break;
		int w = g[v][i];
		if (live[w] && !u[w]) {
			push_from(w, a[w]);
			int t = min(x, V - a[w]);
			if (t > 0) {
				x -= t;
				a[w] += t;
				a[v] -= t;
				ans.pb(mp(mp(v, w), t));
			}
		}
	}
}

void push_to(int v, int x) {
	u[v] = 1;
	forn(i, g[v].size()) {
		if (x == 0) break;
		int w = g[v][i];
		if (live[w] && !u[w]) {
			push_to(w, V - a[w]);
			int t = min(x, a[w]);
			if (t > 0) {
				x -= t;
				a[w] -= t;
				a[v] += t;
				ans.pb(mp(mp(w, v), t));
			}
		}
	}
}

void erase(int v) {
	g[v].resize(0);
	forn(i, n)
		forn(j, g[i].size())
			if (g[i][j] == v) {
				swap(g[i][j], g[i].back());
				g[i].pop_back();
				j--;
			}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("ouVput.txt", "w", stdout);
	cin >> n >> V >> m;
	forn(i, n)
		cin >> a[i];
	forn(i, n)
		cin >> b[i];
	forn(i, n)
		l[i] = i;
	forn(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		if (leader(x) != leader(y)) {
			unite(x, y);
			g[x].pb(y);
			g[y].pb(x);
		}
	}
	seta(live, 1);
	forn(ii, n) {
		forn(j, n)
			if (live[j] && g[j].size() == 0) {
				if (a[j] != b[j]) {
					cout << "NO" << endl;
					return 0;
				}
				live[j] = 0;
				erase(j);
			} else if (live[j] && g[j].size() == 1) {
				seta(u, 0);
				push_from(j, a[j]);
				if (a[j] > b[j]) {
					cout << "NO" << endl;
					return 0;
				}
				seta(u, 0);
				push_to(j, b[j] - a[j]);
				if (a[j] != b[j]) {
					cout << "NO" << endl;
					return 0;
				}
				live[j] = 0;
				erase(j);
			}
	}
	cout << ans.size() << endl;
	forn(i, ans.size())
		printf("%d %d %d\n", ans[i].fs.fs + 1, ans[i].fs.sc + 1, ans[i].sc);	
	return 0;
}