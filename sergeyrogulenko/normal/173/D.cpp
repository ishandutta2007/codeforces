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

vector <int> g[100000], a[2];
int n, m, KK;
int col[100000];
bool u[100000];
int ans[100000];

void go (int v) {
	forn (i, g[v].size())
		if (col[g[v][i]] == -1) {
			col[g[v][i]] = col[v] ^ 1;
			go (g[v][i]);
		}
}

void add (int v) {
	ans[v] = KK;
	seta (u, 0);
	forn (i, g[v].size())
		u[g[v][i]] = 1;
	int cnt = 0;
	forn (i, n)
		if (col[i] != col[v] && !u[i]) {
			if (cnt == 2)
				break;
			cnt ++;
			ans[i] = KK;
		}
	KK ++;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	KK = 0;
	seta (ans, 255);
	scanf ("%d%d", &n, &m);	
	forn (i, m) {
		int x, y;
		scanf ("%d%d", &x, &y);
		x --;
		y --;
		g[x].pb (y);
		g[y].pb (x);
	}
	seta (col, 255);
	forn (i, n)
		if (col[i] == -1) {
			col[i] = 0;
			go (i);
		}
	seta (u, 0);
	forn (i, n)
		a[col[i]].pb (i);
	if (a[0].size() % 3 != 0) {
		int o0 = a[0].size() % 3;
		if (o0 == 2) 
			swap (a[0], a[1]);
		int L = a[0].size();
		int R = a[1].size();
		int v = -1;
		forn (i, a[0].size()) {
			int w = a[0][i];
			if (I g[w].size() <= R-2)
				v = w;
		}
		if (v != -1) 
			add (v);
		
		else {
			vector <int> tmp;
			forn (i, a[1].size()) {
				int w = a[1][i];
				if (I g[w].size() <= L-2 && tmp.size() < 2)
					tmp.pb (w);
			}
			if (tmp.size() < 2) {
				cout << "NO" << endl;
				return 0;
			}
			add (tmp[0]);
			add (tmp[1]);
		}
	}
	printf ("YES\n");
	int cnt = 0;
	forn (ii, 2)
		forn (j, a[ii].size())
			if (ans[a[ii][j]] == -1) {
				ans[a[ii][j]] = KK;
				cnt ++;
				if (cnt == 3) {
					cnt = 0;
					KK ++;
				}
			}
	forn (i, n) {
		printf ("%d", ans[i] + 1);
		if (i + 1 < n)
			printf (" ");
		else
			printf ("\n");					
	}
	return 0;
}