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

int n, m;
int a[100500], b[100500];
int pa[100500], pb[100500], d[100500];
int t[100500* 4];
int lst;

void update(int v, int l, int r, int a, int b, int x) {
	if (r < a || l > b) return;
	if (a <= l && r <= b) {
		t[v] = x;
		return;
	}
	int mid = (l + r) / 2;
	update(v * 2, l, mid , a, b, x);
	update(v * 2 + 1, mid + 1, r, a, b, x);
}

int get(int v) {
	v = v + lst;
	int res = t[v];
	while (v > 1) {
		v >>= 1;
		res = max(res, t[v]);
	}
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);
	lst = 1;
	while (lst < n)
		lst *= 2;
	seta(t, 0);
	for(int i = 1; i <= m; i++) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			scanf("%d%d%d", &pa[i], &pb[i], &d[i]);
			pa[i]--;
			pb[i]--;
			update(1, 0, lst-1, pb[i], pb[i] + d[i] - 1, i);
		} else {
			int v;
			scanf("%d", &v);
			v--;
			int pos = v;
			v = get(v);
			if (v == 0)
				printf("%d\n", b[pos]);
			else
				printf("%d\n", a[pos-pb[v]+pa[v]]); 
		}
	}					
	return 0;
}