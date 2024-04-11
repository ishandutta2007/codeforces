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

int n, k;
vector <pii> a, b;
vector < vector <pii> > res;
bool u[1010];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &k);
	a.clear ();
	b.clear ();
	res.clear ();
	res.resize (k);
	forn (i, k)
		res[i].clear ();
	int64 sum = 0;
	forn (i, n) {
		int x, y;
		scanf ("%d%d", &x, &y);
		sum += x * 2;
		if (y == 1)
			a.pb (mp (x, i+1));
		else
			b.pb (mp (x, i+1));
	}
	sort (all (a));
	sort (all (b));
	int cur = k-1;
	seta (u, 0);
	ford (i, a.size()) {
		res[cur].pb (a[i]);
		u[cur] = 1;
		cur --;
		if (cur < 0)
			cur = 0;
	}
	ford (i, b.size()) {
		res[cur].pb (b[i]);
		cur --;
		if (cur < 0)
			cur = 0;
	}
	forn (i, k)
		sort (all (res[i]));
	forn (i, k)
		if (u[i]) {
			sum -= res[i][0].fs;
		}
	cout << sum / 2 << "." << (sum%2)*5 << endl;
	forn (i, k) {
		printf ("%d", res[i].size());
		forn (j, res[i].size())
			printf (" %d", res[i][j].sc);
		cout << endl;
	}
	return 0;
}