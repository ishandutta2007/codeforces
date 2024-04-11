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

int f[100500];
int n;
int ans;

void update(int v) {
	vector<int> d;
	for (int i = 2; i * i <= v; i ++)
		if (v % i == 0) {
			d.pb(i);
			while (v % i == 0)
				v /= i;
		}
	if (v > 1)
		d.pb(v);
	int cur = 0;
	forn(i, d.size())
		cur = max(cur, f[d[i]]);
	cur++;
	ans = max(ans, cur);
	forn(i, d.size())
		f[d[i]] = max(f[d[i]], cur);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta(f, 0);
	scanf("%d", &n);
	ans = 0;
	forn(i, n) {
		int x;
		scanf("%d", &x);
		update(x);
	}
	cout << ans << endl;
	return 0;
}