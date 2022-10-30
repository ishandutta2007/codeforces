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
int f[100000];
vector <int> g[100000], gt[100000];
bool u1[100000], u2[100000];

void go (int v, bool *u, vector <int> *g, int tp) {
	if (u[v])
		return;
	u[v] = 1;
	if (f[v] == tp)
		return;
	forn (i, g[v].size())
		go (g[v][i], u, g, tp);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta (u1, 0);
	seta (u2, 0);
	cin >> n >> m;
	forn (i, n)
		scanf ("%d", &f[i]);
	forn (i, m) {
		int x, y;
		scanf ("%d%d", &x, &y);
		x --;
		y --;
		g[x].pb (y);
		gt[y].pb (x);
	}
	forn (i, n)
		if (f[i] == 1 && !u1[i])
			go (i, u1, g, -1);
	forn (i, n)
		if (f[i] == 2 && !u2[i])
			go (i, u2, gt, 1);
	forn (i, n)
		if (u1[i] && u2[i])
			puts ("1");
		else
			puts ("0");					
	return 0;
}