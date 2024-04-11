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

int n, m, p;
int x[20200], y[20200];

inline int f (int a, int b) {
	int res = x[a] + y[b];
	if (res >= p)
		res -= p;
	return res;
}

int64 t1[20200], t2[20200], t3[20200];

void go (int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		forn (i, y2-y1)
			printf ("S");
		return;
	}
	if (y1 == y2) {
		forn (i, x2-x1)
			printf ("C");
		return;
	}
	int mid = (x1 + x2) / 2;
	t1[y1] = f(x1,y1);
	for (int i = y1+1; i <= y2; i ++)
		t1[i] = t1[i-1] + f(x1,i);
	for (int i = x1+1; i <= mid; i ++) {
		t2[y1] = t1[y1] + f (i, y1);
		for (int j = y1+1; j <= y2; j ++)
			t2[j] = f(i,j) + max (t2[j-1], t1[j]);
		for (int j = y1; j <= y2; j ++)
			t1[j] = t2[j];
	}	
	for (int j = y1; j <= y2; j ++)
		t3[j] = t1[j];


	t1[y2] = f(x2,y2);
	for (int i = y2-1; i >= y1; i --)
		t1[i] = t1[i+1] + f(x2,i);
	for (int i = x2-1; i >= mid+1; i --) {
		t2[y2] = t1[y2] + f (i, y2);
		for (int j = y2-1; j >= y1; j --)
			t2[j] = f(i,j) + max (t2[j+1], t1[j]);
		for (int j = y1; j <= y2; j ++)
			t1[j] = t2[j];
	}	
	int best1 = y1;
	for (int j = y1; j <= y2; j ++)
		if (t1[best1] + t3[best1] < t1[j] + t3[j])
			best1 = j;

	go (x1, y1, mid, best1);
	printf ("C");
	go (mid+1, best1, x2, y2);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d%d", &n, &m, &p);
	forn (i, n) {
		scanf ("%d", &x[i]);
		x[i] %= p;
	}
	forn (i, m) {
		scanf ("%d", &y[i]);
		y[i] %= p;
	}
	int64 best = 0;
	seta (t1, 0);
	t1[0] = f(0, 0);
	for (int i = 1; i < m; i ++)
		t1[i] = t1[i-1] + f(0, i);
	for (int i = 1; i < n; i ++) {
		seta (t2, 0);		
		t2[0] = t1[0] + f (i, 0);
		for (int j = 1; j < m; j ++)
			t2[j] = f(i,j) + max (t2[j-1], t1[j]);
		memcpy (t1, t2, sizeof (t2));
	}
	best = t1[m-1];
	cout << best << endl;
	go (0, 0, n-1, m-1);
	cout << endl;
	return 0;
}