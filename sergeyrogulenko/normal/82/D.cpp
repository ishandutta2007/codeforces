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
int t[1100][1100];
int a[1100];

int go (int f, int l) {
	if (l == n) 
		return t[f][l] = a[f];
	if (l == n-1)
		return t[f][l] = max (a[f], a[l]);
	if (t[f][l] != -1)
		return t[f][l];
	int c1 = f;
	int c2 = l;
	int c3 = l+1;
	l += 2;
	int res = inf;
	res = min (res, go (c3, l) + max (a[c1], a[c2]));
	res = min (res, go (c2, l) + max (a[c1], a[c3]));
	res = min (res, go (c1, l) + max (a[c3], a[c2]));
	return t[f][l-2] = res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	forn (i, n)
		cin >> a[i];
	seta (t, 255);
	cout << go (0, 1) << endl;
	int f = 0;
	int l = 1;
	while (l < n-1) {
		int c1 = f;
		int c2 = l;
		int c3 = l+1;
		l += 2;
		int res = t[f][l-2];
		if (res == go (c3, l) + max (a[c1], a[c2])) {
			cout << c1+1 << " " << c2+1 << endl;
			f = c3;
		} else
		if (res == go (c2, l) + max (a[c1], a[c3])) {
			cout << c1+1 << " " << c3+1 << endl;
			f = c2;
		} else {
			cout << c3+1 << " " << c2+1 << endl;
			f = c1;
		}
	}
	cout << f+1;
	if (l == n-1)
		cout << " " << l+1;
	cout << endl;
	return 0;
}