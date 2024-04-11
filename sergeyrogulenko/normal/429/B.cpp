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

int t[4][1050][1050];
int n, m;
int a[1050][1050];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	forn(i, n)
		forn(j, m)
			scanf("%d", &a[i + 1][j + 1]);
	seta(t, 0);				
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			t[0][i][j] = max(t[0][i-1][j], t[0][i][j-1]) + a[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			t[1][i][j] = max(t[1][i-1][j], t[1][i][j+1]) + a[i][j];

	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			t[2][i][j] = max(t[2][i+1][j], t[2][i][j-1]) + a[i][j];

	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			t[3][i][j] = max(t[3][i+1][j], t[3][i][j+1]) + a[i][j];
	

	int ans = 0;
	for (int i = 2; i <= n-1; i++)
		for (int j = 2; j <= m-1; j++) {
			ans = max(ans, t[0][i-1][j] + t[3][i+1][j] + t[2][i][j-1] + t[1][i][j+1]);

			ans = max(ans, t[0][i][j-1] + t[3][i][j+1] + t[2][i+1][j] + t[1][i-1][j]);
		}
	cout << ans << endl;
	return 0;
}