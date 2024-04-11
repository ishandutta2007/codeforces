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

int f[1001][1001];

int calc (int a, int b) {
	if (f[a][b] != -1)
		return f[a][b];
	if (a > b)
		return f[a][b] = calc (b, a);
	if (a == 0)
		return f[a][b] = 0;
	f[a][b] = 0;
	if (calc (b % a, a) == 0)
		return f[a][b] = 1;
	int x = a;
	while (b - x >= 0) {
		if (calc (b-x, a) == 0)
			return f[a][b] = 1;
		x *= a;
	}
	return f[a][b];
}

int calc_3 (int64 x, int64 a, int tp) {
	if (x == 0)
		return tp ^ 1;
	int64 end = (x % a) & 1;
	tp ^= end;
	return tp ^ 1;
	
}

int calc_2 (int64 x, int64 a, int tp) {
	if (a & 1)
		return (x & 1) ^ tp ^ 1;
	if (x == 0)
		return tp^1;
	x %= (a + 1);
	return (x & 1) ^ tp ^ 1;
	int64 end = (x % a) & 1;
	tp ^= end;
	x -= x % a;
	if (a & 1)
		return (x & 1) ^ tp ^ 1;
	return calc_3 (x / a, a, tp);
}

int calc_fast (int64 a, int64 b) {
	if (a > b)
		swap (a, b);
	if (a == 0)
		return 0;
	if (calc_fast (b % a, a) == 0)
		return 1;
	return calc_2 (b/a, a, 0);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn (ii, tt) {
		int64 a, b;
		cin >> a >> b;
		int x = calc_fast (a, b);
		if (x == 1)
			puts ("First");
		else
			puts ("Second");
	}
	//	seta (f, 255);
//	forn (i, 1001)
//		forn (j, 1001)
//			if (calc (i, j) != calc_fast (i, j))
//				cerr << i << " " << j << " " << calc (i, j) << " " << calc_fast (i, j) << endl;
	return 0;
}