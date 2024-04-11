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

int x[250], y[250];
int n, m;
int ans[1001000];

int gcd (int a, int b) {
	return a ? gcd (b % a, a) : b;
}

pii get (int x, int y) {
	int d = gcd (abs (x), abs (y));
	x /= d;
	y /= d;
	pii res = mp (x, y);
	return min (res, mp (-x, -y));
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	forn (i, m)
		cin >> x[i] >> y[i];
	forn (i, n)
		ans[i] = 1;
	forn (i, m)
		forn (j, i) {
			pii v = get (x[j] - x[i], y[j] - y[i]);
			int tmp = 2;
			forn (k, m)
				if (i != k && k != j) {
					pii w = get (x[k] - x[i], y[k] - y[i]);
					if (w == v)
						tmp ++;
				}
			if (v.sc == 0)
				continue;
			int64 t = -y[i] / v.sc;
			int64 X = x[i] + t * (int64)v.fs;
			int64 Y = y[i] + t * (int64)v.sc;
			if (Y == 0 && 1 <= X && X <= n)
				ans[X-1] = max (ans[X-1], tmp);

		} 
	int64 res = 0;
	forn (i, n)
		res += (int64)ans[i];
	cout << res << endl;							
	return 0;
}