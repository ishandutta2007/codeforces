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
vector<pii> a;
vector< vector<int> > g;
vector<int> pos[100500];
int col[200500];

void error() {
	cout << -1 << endl;
	exit(0);
}

void go(int v, int c) {
	col[v]= c;
	forn(i, g[v].size())
		if (col[g[v][i]] == -1)
			go(g[v][i], 1 - c);
		else if (col[g[v][i]] == c)
			error();				
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	a.clear();
	forn(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		x *= 2;
		y *= 2;
		a.pb(mp(x-1, i));
		a.pb(mp(y, i));
	}	
	sort(all(a));
	forn(i, a.size())
		pos[a[i].sc].pb(i);
	g.resize(n * 2);
	forn(i, n) {
		g[i * 2].pb(i * 2 + 1);
		g[i * 2 + 1].pb(i * 2);

		g[pos[i][0]].pb(pos[i][1]);
		g[pos[i][1]].pb(pos[i][0]);
	}
	seta(col, 255);
	forn(i, n * 2)
		if (col[i] == -1)
			go(i, 0);
	forn(i, n)
		printf("%d ", col[pos[i][0]]);
	printf("\n");
	return 0;
}