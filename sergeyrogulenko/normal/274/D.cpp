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

int n, m, k;
vector<pii> a;
vector<int> g[300500];
int u[300500];
vector<int> q;

void go(int v) {
	u[v] = 1;
	forn(i, g[v].size())
		if (u[g[v][i]] == 0)
			go(g[v][i]);
		else if (u[g[v][i]] == 1) {
			cout << -1 << endl;
			exit(0);
		}
	u[v] = 2;
	q.pb(v);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	k = m;
	forn(i, n) {
		a.clear();
		forn(j, m) {
			int x;
			scanf("%d", &x);
			if (x != -1)
				a.pb(mp(x, j));
		}		
		sort(all(a));
		if (a.size() == 0) continue;
		int l = 0;
		int r = l;
		while (r+1 < I a.size() && a[r+1].fs == a[l].fs) r++;
		while (r + 1 < I a.size()) {
			int l2 = r + 1;
			int r2 = l2;
			while (r2 + 1 < I a.size() && a[r2+1].fs == a[l2].fs) r2++;
			for (int j = l; j <= r; j++)
				g[a[j].sc].pb(k);
			for (int j = l2; j <= r2; j++)
				g[k].pb(a[j].sc);
			k++;
			l = l2;
			r = r2;
		}
	}
	seta(u, 0);
	q.clear();
	forn(i, m)
		if (!u[i])
			go(i);
	ford(i, q.size())
		if (q[i] < m)
			printf("%d ", q[i] + 1);
	cout << endl;
	return 0;
}