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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

struct state {
	int l, r, n;
};

bool operator < (const state& a, const state& b) {
	return a.l < b.l;
}

int n, m;
int a[500500];
state states[500500];
int prev[500500];
int nxt[500500];
map<int, int> pos;
int lst;
int t[500500 * 4];
int ans[500500];

void update(int v, int value) {
	v += lst;
	t[v] = value;
	while (v > 1) {
		v >>= 1;
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}

void remove(int v) {
	update(v, inf);
	if (nxt[v] != inf) {
		update(v + nxt[v], inf);
	}
}

int get(int v, int l, int r, int a, int b) {
	if (r < a || l > b) return inf;
	if (a <= l && r <= b) return t[v];
	int mid = (l + r) >> 1;
	return min(get(v * 2, l, mid, a, b), get(v * 2 + 1, mid + 1, r, a, b));
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	forn(i, n) {
		nxt[i] = prev[i] = inf;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
		int p = -1;
		if (pos.count(a[i])) {
			p = pos[a[i]];
			nxt[p] = i - p;
			prev[i] = i - p;
		}
		pos[a[i]] = i;
	}
	forn(i, m) {
		int l, r;
		scanf("%d%d", &l, &r);
		state s;
		s.l = l - 1;
		s.r = r - 1;
		s.n = i;
		states[i] = s;
	}
	lst = 1;
	while (lst < n) lst *= 2;
	forn(i, lst) {
		if (i < n) {
			t[i + lst] = prev[i];
		} else {
			t[i + lst] = inf;
		}
	}
	for (int i = lst - 1; i >= 1; i--) {
		t[i] = min(t[i * 2], t[i * 2 + 1]);
	}
	int cur = 0;
	sort(states, states + m);
	forn(i, m) {
		while (cur < states[i].l) {
			remove(cur);
			cur++;
		}
		int res = get(1, 0, lst - 1, states[i].l, states[i].r);
		if (res >= inf) res = -1;
		ans[states[i].n] = res;
	}
	forn(i, m) {
		printf("%d\n", ans[i]);
	}
	return 0;
}