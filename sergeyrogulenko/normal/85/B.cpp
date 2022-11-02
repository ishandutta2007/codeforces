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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
vector <int> a;
multiset <int64> S[3];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int64 k[3];
	int64 t[3];
	forn (i, 3)
		cin >> k[i];
	forn (i, 3)
		cin >> t[i];
	cin >> n;
	a.resize (n);
	forn (i, n)
		scanf ("%d", &a[i]);
	forn (i, 3)
		k[i] = min (k[i], (int64)n);
	forn (i, 3)
		forn (j, k[i])
			S[i].insert (0);
	sort (all (a));
	int64 res = 0;
	forn (i, n) {
		int64 tm = a[i];
		int64 St = a[i];
		int64 Fn = St;
		forn (i, 3) {
			int64 ct = *S[i].begin();
			S[i].erase (S[i].begin());
			tm = max (ct, tm);
			tm += t[i];
			S[i].insert (tm);
		}
		Fn = tm;
		res = max (res, Fn - St);
	}
	cout << res << endl;

	return 0;
}