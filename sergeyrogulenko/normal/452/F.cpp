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
#define hash hash35

typedef long long int64;
typedef pair <int, int> pii;
typedef pair <int64, int64> pii64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n;
int a[300500];
bool left[300500];
const int64 P[2] = {1000000007, 1000000009};
const int64 d[2] = {239, 997};

int64 p[300500][2];
pii64 h[2 * 524288][2];
const int lst = 524288;

void answer() {
	cout << "YES" << endl;
	exit(0);
}

int64 mod(int64 a, int64 p) {
	if (a >= p)
		a -= p;
	return a;
}

pii64 operator + (pii64 a, pii64 b) {
	return pii64(mod((a.fs + b.fs), P[0]), mod((a.sc + b.sc), P[1]));
}

pii64 operator - (pii64 a, pii64 b) {
	return pii64(mod((a.fs - b.fs + P[0]), P[0]), mod((a.sc - b.sc + P[1]), P[1]));
}

void update2(int v, int l, int r, int a, int b, int hn, pii64 add) {
	if (r < a || l > b) return;
	if (a <= l && r <= b) {
		h[v][hn] = h[v][hn] + add;	
		return;
	}
	int mid = (l + r) / 2;
	update2(v * 2, l, mid ,a ,b, hn, add);
	update2(v * 2 + 1, mid+1, r ,a ,b, hn, add);
}

void update1(int pos, int hn) {
	update2(1, 0, lst - 1, pos, n, hn, pii64(p[pos][0], p[pos][1]));	
}

pii64 get_hash(int pos, int hn) {
	pos = pos + lst;
	pii64 res = h[pos][hn];
	while (pos > 1) {
		pos >>= 1;
		res = res + h[pos][hn];		
	}
	return res;
}

void update(int x) {
	update1(x, 0);
	update1(n-x+1, 1);
}

pii64 hash(int pos, int d, int hn) {
	return get_hash(pos + d - 1, hn) - get_hash(pos - 1, hn);
}

pii64 up(pii64 h, int d) {
	return pii64(h.fs * p[d][0] % P[0], h.sc * p[d][1] % P[1]);
}

bool check(int l, int r) {
	int d = (r - l + 1);
	int nd = (d + 1) / 2;
	pii64 ha1 = hash(l, nd, 0);
	pii64 ha2 = hash(n - r + 1, nd, 1);
	ha1 = up(ha1, n - r + 1);
	ha2 = up(ha2, l);
	return ha1 != ha2;
}

void init() {
	p[0][0] = p[0][1] = 1;
	for (int i = 1; i < 300500; i++) {
		p[i][0] = p[i-1][0] * d[0] % P[0];
		p[i][1] = p[i-1][1] * d[1] % P[1];
	}
	seta(h, 0);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	init();
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n) {
		int l = 1;
		int r = a[i] * 2 - 1;
		int d = max(0, r - n);
		l += d;
		r -= d;
		if (l <= r && check(l, r))
			answer();
		update(a[i]);
	}			
	cout << "NO" << endl;
	return 0;
}