#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int64 n, m, k;
int64 ans;

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m >> k;
	if (n - 1 + m - 1 < k) {
		cout << -1 << endl;
		return 0;
	}
	ans = 1;
	int64 x = n;
	int64 cx = 0;
	int64 y;
	while (x >= 1) {
		if (cx + m - 1 >= k) {  
			if (k - cx <= 0)
				y = m;
			else
				y = m / ((k - cx) + 1);
			ans = max(ans, x * y);
		}		
		int64 nx = x - 1;
		int64 ncx = cx + 1;
		x = min(nx, n / (ncx + 1));
		if (x <= 0) break;
		cx = n / x - 1;
	}
	cout << ans << endl;
	return 0;
}