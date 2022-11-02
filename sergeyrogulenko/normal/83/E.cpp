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

int d;
int n;
int a[200000], at[200000], dp[200000];
char buf[30];
int list;
int t[2097152], ta[2097152], s;

int f (int a, int b) {
	int res = d;
	while (a != b) {
		b >>= 1;
		if (a & (1 << (res-1)))
			a ^= (1 << (res-1));
		res --;
	}
	return d - res;
}

void push (int v) {
	t[v] += ta[v];
	if (v < list) {
		ta[v*2] += ta[v];
		ta[v*2+1] += ta[v];
	}
	ta[v] = 0;
}

void update (int v, int l, int r, int a, int x) {
	push (v);
	if (r < a || l > a)
		return;
	if (l == a && r == a) {
		t[v] = min (t[v], x);
		return;
	}
	int m = (l + r) / 2;
	update (v*2, l, m, a, x);
	update (v*2+1, m+1, r, a, x);
	t[v] = min (t[v*2], t[v*2+1]);
}

int rmq (int v, int l, int r, int a, int b) {
	push (v);
	if (r < a || l > b)
		return inf;
	if (a <= l && r <= b) 
		return t[v];
	int m = (l + r) / 2;
	return min (rmq (v*2, l, m, a, b),
		rmq (v*2+1, m+1, r, a, b));
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	forn (i, n) {
		scanf ("%s", buf);
		d = strlen (buf);
		a[i] = at[i] = 0;
		forn (j, d) {
			a[i] = a[i] * 2 + buf[j] - '0';
			at[i] = at[i] * 2 + buf[d-j-1] - '0';
		}
	}
	if (n == 1) {
		cout << d << endl;
		return 0;
	}
	list = 1 << d;
	forn (i, list*2)
		t[i] = inf;
	seta (ta, 0);
	s = d;
	update (1, 0, list-1, at[0], s+d);
	dp[0] = s+d;
	for (int i = 1; i < n-1; i ++) {
		int v = f(a[i-1], a[i]);
		s += v;
		dp[i] = s+d;
		ta[1] += v;
		update (1, 0, list-1, at[i-1], dp[i-1]);
		forn (j, d+1) {
			int atc = at[i+1] & ((1 << j) - 1);
			int l = atc << (d-j);
			int r = l + (1 << (d-j)) - 1;
			dp[i] = min (dp[i], rmq (1, 0, list-1, l, r) + d-j);
		}
	}
	s += f(a[n-2], a[n-1]);
	int res = s;
	s = 0;
	for (int i = n-2; i >= 0; i --) {
		res = min (res, dp[i] + s);
		s += f (a[i], a[i+1]);
	}
	cout << res << endl;
	return 0;
}