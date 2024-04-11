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

vector <int> x;
map <int, int> X;
vector <pii> A;
int n, m;
int t[1000000], s[1000000];
const int P = 1000000007;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &m);
	x.clear ();
	x.pb (0);
	x.pb (-1);
	x.pb (n);
	A.resize (m);
	forn (i, m) {
		scanf ("%d%d", &A[i].fs, &A[i].sc);
		x.pb (A[i].fs);
		x.pb (A[i].sc);
	}
	sort (all (x));
	x.resize (unique (all (x)) - x.begin());
	forn (i, x.size())
		X[x[i]] = i;
	n = X[n];
	forn (i, m) {
		A[i].fs = X[A[i].fs];
		A[i].sc = X[A[i].sc];
		swap (A[i].fs, A[i].sc);
	}
	sort (all (A));
	seta (s, 0);
	seta (t, 0);
	t[1] = 1;
	s[1] = 1;
	int p = 0;
	for (int i = 2; i <= n; i ++) {
		while (p < m && A[p].fs == i) {
			t[i] = (t[i] + s[i-1] - s[A[p].sc-1]) % P;
			t[i] = (t[i] + P) % P;
			p ++;
		}
		s[i] = (s[i-1] + t[i]) % P;
	}
	

	cout << t[n] << endl;
	return 0;
}