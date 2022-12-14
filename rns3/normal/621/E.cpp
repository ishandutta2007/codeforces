#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int((x).size()))
#define bit(x) (1 << (x))
#define cnt1(x) (__builtin_popcount(x))

template<class T, class U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template<class T, class U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int MX = 105;
const int M = 1000000007;
int x;
int r[MX][MX], a[MX][MX];
int tp[MX][MX];
int c[10];

inline void add(int& x, int y) {
	x += y;
	if (x >= M) x -= M;
}

void mul(int a[MX][MX], int b[MX][MX]) {
	int i, j, k, val;
	
	for (i = 0; i < x; i++) {
		for (j = 0; j < x; j++) {
			val = 0;
			for (k = 0; k < x; k++) add(val, LL(a[i][k]) * b[k][j] % M);
			tp[i][j] = val;
		}
	}
	for (i = 0; i < x; i++) {
		for (j = 0; j < x; j++) a[i][j] = tp[i][j];
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int n, b, k, i, t;
	
	scanf("%d%d%d%d", &n, &b, &k, &x);
	while (n--) {
		scanf("%d", &t);
		c[t]++;
	}
	for (i = 0; i < x; i++) {
		for (t = 0; t < 10; t++) {
			add(a[i][(i * 10 + t) % x], c[t]);
		}
	}
	for (i = 0; i < x; i++) r[i][i]++;
	for (; b; b /= 2) {
		if (b & 1) mul(r, a);
		mul(a, a);
	}
	printf("%d\n", r[0][k]);
	return 0;
}