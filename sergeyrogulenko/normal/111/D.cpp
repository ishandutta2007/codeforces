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

template <class T> T sqr (T x) {return x * x;}

const int64 P = 1000000007;
int64 f[1001000];
int64 c[1011][1011];

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

int64 calc (int k, int i) {
	return f[k] * power (f[i], P-2) % P * power (f[k-i], P-2) % P;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta (c, 0);
	c[0][0] = 1;
	for (int i = 0; i <= 1000; i ++)
		for (int j = 0; j <= 1000; j ++) {
			c[i][j+1] = (c[i][j+1] + c[i][j] * i) % P;
			c[i+1][j] = (c[i+1][j] + c[i][j]) % P;
		}
        f[0] = 1;
        for (int i = 1; i <= 1000000; i ++)
        	f[i] = (f[i-1] * (i)) % P;
	int n, m, k;
	cin >> n >> m >> k;
	if (m == 1) {
		cout << power (k, n) << endl;
		return 0;
	}
	int64 res = 0;
	for (int i = 0; i <= min (k, n); i ++) {
		int64 x = calc (k, i);
		int64 tmp = 0;
		for (int j = 0; j + i <= min (k, n) && j*2+i <= k; j ++) 
			if (i + j > 0) {
			int64 xtmp = c[i+j][n-i-j] * f[i+j] % P;
			xtmp = xtmp * xtmp % P;
			xtmp = xtmp * calc (k-i, j) % P;
			xtmp = xtmp * calc (k-i-j, j) % P;
			tmp = (tmp + xtmp) % P;
		}
		int64 y = 1;
		if (m > 2)
			y = power (i, n * (m-2));
		x = x * tmp % P * y % P;
		res = (res + x) % P;
	}
	cout << res << endl;
	return 0;
}