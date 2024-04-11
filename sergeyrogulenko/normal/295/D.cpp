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

const int64 P = 1000000007;

int64 t[2001][2001];
int64 t1[2001][2001];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta(t, 0);
	int n = 2000;
	for (int i = 1; i <= n; i++) {
		int64 s = 0;
		for (int j = 1; j <= n; j++) {
			s = (s + t[i-1][j]) % P;
			t[i][j] = (t[i][j-1] + s) % P;
		}
		for (int j = 1; j <= n; j++)
			t[i][j] = (t[i][j] + 1) % P;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			t1[i][j] = (t[i][j] - t[i-1][j] + P) % P;
	int64 res = 0;
	cin >> n;
	int m;
	cin >> m;
	m--;
	if (m <= 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res = (res + t[i][j] * t1[n-i+1][j] % P * (m - j + 1)) % P;
		}
	}
	cout << res << endl;
	return 0;
}