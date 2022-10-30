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

int64 res;

int a[8];
int g[8][8];

int ans[9] = {0, 1, 2, 3, 4, 5, 7776, 117649, 2097152};

int64 power(int64 a, int64 b, int64 P) {
	int64 res = 1;
	while (b) {
		if (b & 1)
			res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res;
}

void check(int n) {
//	if (a[0] == 0) return;
	seta(g, 0);
	forn(i, n)
		g[i][a[i]] = 1;
	forn(i, n)
		g[i][i] = 1;
	forn(k, n)
		forn(i, n)
			forn(j, n)
				g[i][j] |= g[i][k] & g[k][j];
	forn(i, n)
		if (!g[i][0]) return;
	res++;
}

void go(int cur, int n, int k) {
	if (cur == k) {
		check(k);
		return;
	}
	forn(i, k) {
		a[cur] = i;
		go(cur+1, n, k);
	}
}

int64 solve(int n, int k) {
	res = 0;
	if (k >= 6)
		res = ans[k];
	else
		go(0, n, k);
	res = res * power(n - k, n - k, P) % P;
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	cout << solve(n, k) << endl;	
	return 0;
}