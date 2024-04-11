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
#define y1 botva

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
vector <pii> g[100000];
int sum[100000], sluck[100000];
int64 ans[100000];

void go (int v, int p) {
	sum[v] = sluck[v] = 0;
	sum[v] = 1;
	forn (i, g[v].size())
		if (g[v][i].fs != p)
			go (g[v][i].fs, v);
	forn (i, g[v].size()) 
		if (g[v][i].fs != p) {
			sum[v] += sum[g[v][i].fs];
			if (g[v][i].sc == 1)
				sluck[v] += sum[g[v][i].fs];
			else
				sluck[v] += sluck[g[v][i].fs];
		}
}

void dfs (int v, int p) {
	forn (i, g[v].size())
		if (g[v][i].fs != p) {
			if (g[v][i].sc == 0)
				ans[g[v][i].fs] = ans[v];
			else
				ans[g[v][i].fs] = sluck[g[v][i].fs] + n-sum[g[v][i].fs];
			dfs (g[v][i].fs, v);
		}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	forn (i, n-1) {
		int x, y, w;
		scanf ("%d%d%d", &x, &y, &w);
		x --;
		y --;
		bool ok = 1;
		while (w) {
			if ((w % 10 != 7) && (w % 10 != 4))
				ok = 0;
			w /= 10;
		}
		w = ok;
		g[x].pb (mp (y, w));
		g[y].pb (mp (x, w));
	}
	seta (sum, 255);
	seta (sluck, 255);
	go (0, -1);
	ans[0] = sluck[0];
	dfs (0, -1);
	int64 res = 0;
	forn (i, n)
		res = (res + ans[i] * (ans[i] - 1));
	cout << res << endl;
	return 0;
}