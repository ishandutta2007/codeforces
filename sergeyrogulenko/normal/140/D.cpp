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

vector <int> a;
int r1, r2;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n;
	r1 = r2 = 0;
	a.clear ();
	cin >> n;
	a.resize (n);
	forn (i, n)
			cin >> a[i];
	sort (all (a));
	int last1 = 350;
	int last2 = 360;
	n ++;
	a.pb (inf);
	int p = 0;
	while (a[p] <= last1) {
		last1 -= a[p];
		p ++;
		r1 ++;
	}
	a[p] -= last1;
	int passed = 0;
	while (a[p] <= last2) {
		passed += a[p];
		r1 ++;
		r2 += passed;
		last2 -= a[p];
		p ++;
	}
	cout << r1 << " " << r2 << endl;
	return 0;
}