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

int64 P;
int deg_in[600], deg_out[600];
vector <int> g[600];
int n, m;
vector <int> a, b;
int d[600];
bool u[600];
vector <int> q;
int num[600];
int64 A[300][300];
int k;

void go (int v) {
	if (u[v])
		return;
	u[v] = 1;
	forn (i, g[v].size())
		go (g[v][i]);
	q.pb (v);
}

int64 power (int64 a, int64 b) {
	int64 res = 1;
	while (b) {
		if (b & 1)
			res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res;
}

int64 det(int64 res) {
	forn (i, n) {
		int x = i;
		for (int j = i; j < n; j ++)
			if (A[j][i] != 0)
				x = j;
		if (A[x][i] == 0)
			return 0;
		if (x != i) {
			res = res * (P - 1) % P;
			forn (j, n)
				swap (A[i][j], A[x][j]);
		}
		res = res * A[i][i] % P;
		int64 y = power (A[i][i], P-2);
		forn (j, n)
			A[i][j] = A[i][j] * y % P;
		forn (j, n)
			if (i != j) {
				int64 q = A[j][i];
				forn (k, n)
					A[j][k] = ((A[j][k] - A[i][k] * q) % P + P) % P;
			}
	}
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &m);
	cin >> P;
	seta (deg_in, 0);
	seta (deg_out, 0);
	k = 0;
	forn (i, m) {
		int x, y;
		scanf ("%d%d", &x, &y);
		x --;
		y --;
		g[x].pb (y);
		deg_out[x] ++;
		deg_in[y] ++;
	}
	int64 cur = 1;
	forn (i, n) {
		if (deg_in[i] == 0 && deg_out[i] == 0) {
			cur = cur * power (P - 1, abs (I a.size() - I b.size())) % P;
			continue;
		}
		if (deg_in[i] == 0)
			a.pb (i);
		if (deg_out[i] == 0) {
			b.pb (i);
			num[i] = k;
			k ++;
		}
	}
	seta (u, 0);
	q.clear ();
	forn (i, n)
		if (!u[i])
			go (i);
	forn (ii, k) {
		int v = a[ii];
		seta (d, 0);
		d[v] = 1;
		ford (j, q.size()) {
			int w = q[j];
			forn (i, g[w].size())
				d[g[w][i]] = (d[g[w][i]] + d[w]) % P;
		}
		forn (j, k)
			A[ii][j] = d[b[j]];
	}
	n = k;
	cout << det(cur) << endl;
	return 0;
}