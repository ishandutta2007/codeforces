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

int n, m, k, q;
int x[200500], y[200500];
pii p1[200500], p2[200500];
bool ans[200500];
int t[100500 * 4];
int lst;

struct state {
	int x, y, t, num;
};

bool operator < (const state& a, const state& b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.t < b.t;
}

vector<state> w;

void update(int v, int x) {
	v += lst;
	t[v] = x;
	while (v > 1) {
		v >>= 1;
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}

int get(int v, int l, int r, int a, int b) {
	if (r < a || l > b) return inf;
	if (a <= l && r <= b) {
		return t[v];
	}
	int mid = (l + r) / 2;
	return min(get(v*2, l, mid, a, b), get(v*2+1, mid+1, r, a, b));
}

void solve() {
	w.clear();
	forn(i, k) {
		state s;
		s.x = x[i];
		s.y = y[i];
		s.t = 2;
		w.pb(s);
	}
	forn(i, q) {
		state s;
		s.x = p2[i].fs;
		s.t = 3;
		s.num = i;
		w.push_back(s);
	}
	sort(all(w));
	lst = 1;
	while (lst < n) lst *= 2;
	for (int i = 1; i < lst * 2; i++)
		t[i] = -1;
	forn(i, w.size()) {
		state s = w[i];
		if (s.t == 2) {
			update(s.y, s.x);
		} else if (s.t == 3) {
			int v = s.num;
			int ly = p1[v].sc;
			int ry = p2[v].sc;
			int mn = get(1, 0, lst - 1, ly, ry);
			if (mn >= p1[v].fs) ans[v] = 1;
		}
	}
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &k, &q);
	n = max(n, m);
	forn(i, k) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
	}
	forn(i, q) {
		scanf("%d%d", &p1[i].fs, &p1[i].sc);
		p1[i].fs--;
		p1[i].sc--;
		scanf("%d%d", &p2[i].fs, &p2[i].sc);
		p2[i].fs--;
		p2[i].sc--;
		ans[i] = false;
	}
	solve();
	forn(i, k) swap(x[i], y[i]);
	forn(i, q) {
		swap(p1[i].fs, p1[i].sc);
		swap(p2[i].fs, p2[i].sc);
	}
	solve();
	forn(i, q) {
		if (ans[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}