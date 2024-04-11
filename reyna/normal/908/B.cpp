// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 55, mod = (int) 0;
int p[] = {0, 1, 2, 3};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
string s[N], com;
int check() {
	int sx, sy, tx, ty;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'S') {
				sx = i;
				sy = j;
			} else if (s[i][j] == 'E') {
				tx = i;
				ty = j;
			}
		}
	for (auto x : com) {
		int dir = p[x - '0'];
		sx += dx[dir];
		sy += dy[dir];
		if (sx < 0 || sx >= n || sy < 0 || sy >= m || s[sx][sy] == '#') return 0;
		if (s[sx][sy] == 'E') return 1;
	}
	return 0;
}
int main() {
	cin >> n >> m;
	for (int j = 0; j < n; ++j)
		cin >> s[j];
	cin >> com;
	int res = 0;
	do {
		res += check();
	} while (next_permutation(p, p + 4));
	cout << res << endl;
}