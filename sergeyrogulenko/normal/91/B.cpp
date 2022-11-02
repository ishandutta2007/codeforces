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
vector <pii> a;
int ans[100000];
int x;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	a.resize (n);
	forn (i, n) {
		a[i].sc = i;
		scanf ("%d", &a[i].fs);
	}
	sort (all (a));
	int l = 0;
	x = -1;
	while (l < n) {
		int r = l;
		while (r + 1 < l && a[r+1].fs == a[l].fs)
			r ++;
		for (int i = l; i <= r; i ++) {
			if (x < a[i].sc)
				ans[a[i].sc] = -1;
			else
				ans[a[i].sc] = x - a[i].sc - 1;
		}
		for (int i = l; i <= r; i ++)
			x = max (x, a[i].sc);
		l = r + 1;
	}
	forn (i, n)
		printf ("%d ", ans[i]);
	cout << endl;
	return 0;
}