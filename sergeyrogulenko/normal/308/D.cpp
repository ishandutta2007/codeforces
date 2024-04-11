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
const int inf = (1 << 20) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int64 slow(int n, int m) {
        int64 res = 0;
        n++;
	for (int i = m+1; i + m < n; i++)
	for (int j = m+1; j + m < n; j++)
	for (int k = m+1; k + m < n; k++)
		if ((i + n - 2 * k) * (-j + n - 2 * k) + 3 * (i - n) * (j - n) < 0)
			res++;
	return res;
}

int64 calc(int n, int m, int k) {
	int64 res = 0;
	for (int j = m+1; j < n-m; j++) {
		int l = 3 * n * (j - n) - (n - 2 * k) * (n - j - 2 * k);
		int r = n - 2 * k - j + 3 * j - 3 * n;
		l *= -1;
		r *= -1;
		int x = l / r + 1;
		if (x < n-m) {
			res += min(n - m - x, n-m-m-1);
		}
	}	
	return res;
}

int64 calc2(int n, int m, int k) {
	int64 res = 0;
	int lf = m+1;
	int rg = n - m - 1;
	while (lf < rg) {
		int j = (lf + rg) / 2;
		int l = (n - j + k) * (2 * n - k) - (3 * n - 3 * k) * k;
		int r = (n - j + k);
		int x = l / r + 1;
		if (x < n - m)
			rg = j;
		else
			lf = j + 1;
	}
	for (int j = lf; j < n-m; j++) {
		int l = (n - j + k) * (2 * n - k) - (3 * n - 3 * k) * k;
		int r = (n - j + k);
		int x = l / r + 1;
		if (x < n-m) {
			if (n - m - x > n - m - m - 1) {
				res += (n-m-j) * (n - m - m - 1);
				break;
			} else 
				res += n - m - x;
		}
	}	
	return res;
}

int64 slow2(int n, int m) {
	int64 res = 0;
	n++;
	for (int k = m+1; k <= n-k; k++) {
		if (k < n - k)
			res += 2 * calc2(n, m, k);
		else
			res += calc2(n, m, k);
	}
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	cout << 3LL * slow2(n, m) << endl;	
//	cerr << clock() << endl;
//	for (int n = 1; n <= 100; n++)
//		cout << slow2(n, 0) << endl;
	return 0;
}