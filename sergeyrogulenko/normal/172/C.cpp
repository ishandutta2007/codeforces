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

int64 ans[100000], x[100000], t[100000];
int n, m;
vector <pair <int64, int> > A;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &m);
	forn (i, n) 
		scanf ("%I64d%I64d", &t[i], &x[i]);
	int64 cur = 0;
	A.clear ();
	int pos = 0;
	while (pos < n) {
		A.clear ();
		while (pos < n && I A.size() < m) {
			cur = max (cur, t[pos]);
			A.pb (mp (x[pos], pos));
			pos ++;
		}
		sort (all (A));
		int i = 0;
		int64 X = 0;
		while (i < I A.size()) {
			cur += A[i].fs - X;
			X = A[i].fs;
			int64 cnt = 0;
			while (i < I A.size() && A[i].fs == X) {
				cnt ++;
				ans[A[i].sc] = cur;
				i ++;
			}
			cur += cnt/2 + 1;
		}
		cur += X;

	}
	forn (i, n) {
		printf ("%I64d", ans[i]);
		if (i + 1 < n)
			printf (" ");
		else
			printf ("\n");
	}

	
	return 0;
}