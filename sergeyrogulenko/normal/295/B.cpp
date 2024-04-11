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

int64 a[500][500];
int64 d[500][500];
int n;
int q[500];
int64 ans[500];
bool u[500];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	forn(i, n)
		forn(j, n)
			scanf("%I64d", &a[i][j]);
	forn(i, n)
		scanf("%d", &q[i]);
	seta(u, 0);
	forn(i, n)
		forn(j, n)
			d[i][j] = inf64;
	ford(ii, n) {
		int v = q[ii] - 1;
		u[v] = 1;
		forn(i, n)
			if (u[i]) {
				d[i][v] = min(d[i][v], a[i][v]);
				d[v][i] = min(d[v][i], a[v][i]);
			}
		forn(i, n) if (u[i])
			forn(j, n) 
				if (u[i] && u[j]) {
					d[i][v] = min(d[i][v], d[i][j] + d[j][v]);
					d[v][i] = min(d[v][i], d[v][j] + d[j][i]);
				}
		forn(i, n) if (u[i])
			forn(j, n)
				if (u[j]) {
					d[i][j] = min(d[i][j], d[i][v] + d[v][j]);
				}					
		int64 res = 0;
		for(int i = ii; i < n; i++)
			for (int j = ii; j < n; j++)
				res += d[q[i]-1][q[j]-1];
		ans[ii] = res;
	}
	forn(i, n)
		cout << ans[i] << " ";
	cout << endl;				
	return 0;
}