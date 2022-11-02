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
const int inf = (1 << 28) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
int a[200];
string s;
int t[200][200], g[200][200][200];

int go (int l, int r, int d) {
	if (d < 0)
		return -inf;
	if (l > r && d == 0)
		return 0;
	if (l > r)
		return -inf;
	if (g[l][r][d] != -1)
		return g[l][r][d];
	int &res = g[l][r][d];
	res = -inf;
	if (r - l + 1 < d && d < 199)
		return res;
	if (d == 199) {
		for (int i = 1; i <= r-l+1; i ++)
			if (a[i] != -1)
				res = max (res, go (l, r, i) + a[i]);
		return res;
	}
	for (int i = 1; i <= r-l+1; i ++) {
		res = max (res, go (l, l+i-1, 199) + go (l+i, r, d));
		res = max (res, go (l, r-i, d) + go (r-i+1, r, 199));
	}
	if (s[l] == s[r]) {
		int d1 = d - 2;
		if (l == r)
			d1 ++;
		res = max (res, go (l+1, r-1, d1));
	}
	return res;
}

int calc (int l, int r) {
	if (l > r)
		return 0;
	if (t[l][r] != -1)
		return t[l][r];
	int &res = t[l][r];
	res = max (res, max (calc (l+1, r), calc (l, r-1)));
	for (int i = 1; i <= r-l+1; i ++)
		res = max (res, go (l, l+i-1, 199) + calc (l+i, r));
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	forn (i, n)
		cin >> a[i+1];
	cin >> s;
	seta (t, 255);
	seta (g, 255);
	cout << calc (0, n-1) << endl;
	return 0;
}