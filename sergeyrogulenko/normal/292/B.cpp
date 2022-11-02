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
vector<int> g[100500];
bool u[100500];
int deg[100500];

void dfs(int v) {
	if (u[v]) return;
	u[v] = 1;
	forn(i, g[v].size())
		dfs(g[v][i]);
}

void answer(string s) {
	cout << s << endl;
	exit(0);
}

bool check1() {
	if (deg[1] == 2 && deg[2] + deg[1] == n) return 1;
	return 0;	
}

bool check2() {
	return deg[2] == n;
}

bool check3() {
	return deg[1] == n-1 && deg[n-1] == 1;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	forn(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	seta(u, 0);
	dfs(0);
	forn(i, n)
		if (!u[i]) 
			answer("unknown topology");
	seta(deg, 0);
	forn(i, n)
		deg[g[i].size()]++;
	if (check1())
		answer("bus topology");
	if (check2())
		answer("ring topology");
	if (check3())
		answer("star topology");
	answer("unknown topology");
	return 0;
}