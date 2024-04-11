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
int64 d[100500];
vector<pii> g[100500];
bool alive[100500];
int ans;
set<pair<int64, int> > S;

void go() {
	S.clear();
	forn(i, n)
		if (d[i] < inf64) {
			S.insert(mp(d[i], i));
		}
	while (S.size() > 0) {
		int v = S.begin()->second;
		S.erase(S.begin());
		forn(i, g[v].size()) {
			int w = g[v][i].fs;
			int64 nd = d[v] + g[v][i].sc;
			if (nd <= d[w] && alive[w]) {
				alive[w] = 0;
				ans++;
			}
			if (nd < d[w]) {
				if (S.count(mp(d[w], w))) {
					S.erase(S.find(mp(d[w], w)));
				}
				d[w] = nd;
				S.insert(mp(d[w], w));
			}
		}
	}
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	forn(i, m) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		g[x].pb(mp(y, z));
		g[y].pb(mp(x, z));	
	}	
	forn(i, n)
		d[i] = inf64;
	d[0] = 0;
	forn(i, k) {
		int x, z;
		scanf("%d%d", &x, &z);
		x--;
		d[x] = min(d[x], (int64)z);
	}
	ans = k;
	forn(i, n)
		if (i > 0 && d[i] < inf64) {
			alive[i] = 1;
			ans--;
		}
	go();
	cout << ans << endl;
	return 0;
}