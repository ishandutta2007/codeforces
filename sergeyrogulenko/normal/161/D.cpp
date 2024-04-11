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

int n, k;
int64 res;
vector <int> g[50500];
int t[50500][501];

void go (int v, int p) {
	t[v][0] = 1;
	forn (i, g[v].size())
		if (g[v][i] != p) {
			go (g[v][i], v);
			for (int j = 1; j <= k; j ++)
				t[v][j] += t[g[v][i]][j-1];
		}
	res += t[v][k]*2;
	forn (i, g[v].size())
		if (g[v][i] != p) {
			for (int j = 1; j < k; j ++)
				res += (int64)t[g[v][i]][j-1] * (int64)(t[v][k-j] - t[g[v][i]][k-j-1]);
		}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &k);
	forn (i, n-1) {
		int x, y;
		scanf ("%d%d", &x, &y);
		x --;
		y --;
		g[x].pb (y);
		g[y].pb (x);
	}
	seta (t, 0);
	res = 0;
	go (0, -1);
	cout << res/2 << endl;
	return 0;
}