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

int n, m, list;
vector <int> A;
vector <pii> Q;
int64 t[262144][7];
int64 s1[7];

void push (int v) {
	t[v][6] %= 5;
	if (t[v][6] == 0)
		return;
	forn (i, 5)
		s1[(i+t[v][6])%5] = t[v][i];
	forn (i, 5)
		t[v][i] = s1[i];
	if (v < list) {
		t[v*2][6] += t[v][6];
		t[v*2+1][6] += t[v][6];
	}
	t[v][6] = 0;
}

void update2 (int v, int l, int r, int a, int b, int ADD) {
	push (v);
	if (r < a || l > b)
		return;
	if (a <= l && r <= b) {
		t[v][6] += ADD;
		push (v);
		return;
	}
	int mid = (l + r) / 2;
	update2 (v*2, l, mid, a, b, ADD);
	update2 (v*2+1, mid+1, r, a, b, ADD);
	forn (i, 6)
		t[v][i] = t[v*2][i] + t[v*2+1][i];
}

void update1 (int v, int l, int r, int a, int b, int wh, int add) {
	push (v);
	if (r < a || l > b)
		return;
	if (a <= l && r <= b) {
		if (add == 4)
			add = -1;
		t[v][wh] += (int64)add * (int64)A[a-1];
		t[v][5] += add;
		push (v);
		return;
	}
	int mid = (l + r) / 2;
	update1 (v*2, l, mid, a, b, wh, add);
	update1 (v*2+1, mid+1, r, a, b, wh, add);
	forn (i, 6)
		t[v][i] = t[v*2][i] + t[v*2+1][i];
}

int64 rsq (int v, int l, int r, int a, int b) {
	push (v);
	if (r < a || l > b)
		return 0;
	if (a <= l && r <= b) 
		return t[v][5];
	int mid = (l + r) / 2;
	int64 c1 = rsq (v*2, l, mid, a, b);
	int64 c2 = rsq (v*2+1, mid+1, r, a, b);
	forn (i, 6)
		t[v][i] = t[v*2][i] + t[v*2+1][i];
	return c1 + c2;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	Q.resize (n);
	forn (i, n) {
		char buf[10];
		scanf ("%s", buf);
		if ((string)buf == (string)"sum")
			Q[i].fs = 0;
		else {
			scanf ("%d", &Q[i].sc);
			if ((string)buf == "add")
				Q[i].fs = 1;
			else
				Q[i].fs = -1;
			A.pb (Q[i].sc);
		}
	}
	sort (all (A));
	A.resize (unique (all (A)) - A.begin());
	m = A.size();
	list = 1;
	while (list < m)
		list *= 2;
	seta (t, 0);
	forn (i, n)
		if (Q[i].fs == 0)
			printf ("%I64d\n", t[1][3]);
		else {
			int v = lower_bound (all (A), Q[i].sc) - A.begin();
			v ++;
			int add = 1;
			if (Q[i].fs == -1)
				add = 4;
			int s = (rsq (1, 1, list, 1, v-1) + 1) % 5;
			update1 (1, 1, list, v, v, s, add);
			update2 (1, 1, list, v+1, list, add);
		}
	return 0;
}