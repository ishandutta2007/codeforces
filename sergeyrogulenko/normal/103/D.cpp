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

int n, m;
int64 w[300300];
int64 t[300300];
vector < pair <pii, int> > Q;
int64 ans[300300];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
/*	printf ("300000\n");
	forn (i, 300000)
		printf ("1000000000\n");
	printf ("300000\n");
	forn (i, 300000)
		printf ("1 %d\n", i+1);
	return 0;*/
	seta (w, 0);
	scanf ("%d", &n);
	forn (i, n) {
		int x;
		scanf ("%d", &x);
		w[i] = x;
	}
	scanf ("%d", &m);
	Q.resize (m);
	forn (i, m) {
		int a, b;
		scanf ("%d%d", &a, &b);
		a --;
		Q[i] = mp (mp (b, a), i);
	}
	sort (all (Q));
	int cur = 0;
	forn (i, Q.size()) {
		int a = Q[i].fs.sc;
		int b = Q[i].fs.fs;
		int num = Q[i].sc;
		if (b > 1000) {
			ans[num] = 0;
			while (a < n) {
				ans[num] += w[a];
				a += b;
			}
		} else {
			if (b > cur) {
				cur = b;
				seta (t, 0);
				for (int i = n-1; i >= 0; i --) {
					t[i] = w[i];
					if (i + cur < n)
						t[i] += t[i+cur];
				}
			}
			if (a < n)
				ans[num] = t[a];
			else
				ans[num] = 0;
		}
	}

	forn (i, m) 
		printf ("%I64d\n", ans[i]);

	return 0;
}