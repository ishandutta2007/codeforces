#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
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
#define next NEXT64
#define prev PREV64
#define y1 Y164

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr(T x) { return x * x; }

int n;
int f[100500];
int list;
int t[400500], s[400500];

void push(int v) {
	if (v < list) {
		s[v*2] += s[v];
		s[v*2+1] += s[v];
	}
	t[v] += s[v];
	s[v] = 0;
}

void add(int v, int l, int r, int a, int b, int x) {
	push(v);
	if (r < a || l > b) return;
	if (a <= l && r <= b) {
		s[v] += x;
		push(v);
		return;
	}
	int mid = (l + r) / 2;
	add(v * 2, l, mid, a, b, x);
	add(v*2+1, mid+1, r, a, b, x);
	t[v] = max(t[v*2], t[v*2+1]);
}

void update(int pos, int k) {
	if (k > 0) k = 1;
	add(1, 0, list-1, 0, pos, k);
}

int get(int v) {
	push(v);
	if (v >= list) return v - list;
	push(v*2);
	push(v*2+1);
	if (t[v*2+1] > 0) return get(v*2+1);
	return get(v*2);
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	list = 1;
	while (list < n) list *= 2;
	seta(t, 0);
	seta(s, 0);
	forn(i, n) {
		int pos, tp, k;
		scanf("%d%d", &pos, &tp);
		if (tp == 1) scanf("%d", &k);
		if (tp == 0) k = -1;
		pos--;
		f[pos] = k;
		update(pos, k);
		if (t[1] <= 0) {
			printf("-1\n");
		} else {
			int idx = get(1);
			printf("%d\n", f[idx]);
		}
	}
	return 0;
}