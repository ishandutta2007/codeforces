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

const int N = (int) 305, mod = (int) 0;
string s[N][N], fn[N][N];
int cnt[2][N], need[2][N];
vector<pair<pair<int, int>, pair<int, int>>> moves;
void move(int a, int b, int c, int d) {
	moves.pb(mp(mp(a, b), mp(c, d)));	
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) cin >> s[j][i];	
	}
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) cin >> fn[j][i];
	}
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < m; ++y) {
			for (int j = (int) s[x][y].size() - 1; j >= 0; --j) {
				char c = s[x][y][j];
				if (c == '0') {
					if (x != 0) {
						move(x, y, 0, y);
						cnt[0][y]++;
					} else {
						if (y == 0) {
							move(x, y, x, y + 1);	
							cnt[0][y + 1]++;
						} else {
							move(x, y, x, y - 1);
							cnt[0][y - 1]++;
						}
					}
				} else {
					if (x != 1) {
						move(x, y, 1, y);
						cnt[1][y]++;
					} else {
						if (y == 0) {
							move(x, y, x, y + 1);	
							cnt[1][y + 1]++;
						} else {
							move(x, y, x, y - 1);
							cnt[1][y - 1]++;
						}
					}
				}
			}
			
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int h0 = 0, h1 = 0;
			for (auto c : fn[i][j]) if (c == '0') h0++; else h1++;
			{
			int y = j;
			if (i == 0) {
				y = (y + m - 1) % m;
			}
			need[0][y] += h0;
			}
			{
			int y = j;
			if (i == 1) {
				y = (y + m - 1) % m;
			}
			need[1][y] += h1;
			}
		}
	for (int r = 0; r <= 1; ++r)
		for (int j = 0; j < m; ++j)
			while (cnt[r][j] < need[r][j]) {
				for (int i = 0; i < m; ++i)
					if (cnt[r][i] > need[r][i] && cnt[r][j] < need[r][j])
						move(r, i, r, j), cnt[r][i]--, cnt[r][j]++;
			}
	for (int i = 2; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			for (int c = (int) fn[i][j].size() - 1; c >= 0; --c)
				if (fn[i][j][c] == '0')
					move(0, j, i, j);
				else
					move(1, j, i, j);
		}
	for (int j = 0; j < m; ++j) {
		for (int c = (int) fn[1][j].size() - 1; c >= 0; --c)
			if (fn[1][j][c] == '0')
				move(0, j, 1, j);
			else
				move(1, (j + m - 1) % m, 1, j);
	}
	for (int j = 0; j < m; ++j) {
		for (int c = (int) fn[0][j].size() - 1; c >= 0; --c)
			if (fn[0][j][c] == '0')
				move(0, (j + m - 1) % m, 0, j);
			else
				move(1, j, 0, j);
	}
	cout << (int) moves.size() << endl;
	for (auto x : moves) {
		cout << x.x.x + 1 << ' ' << x.x.y + 1 << ' ' << x.y.x  + 1 << ' ' << x.y.y + 1 << '\n';	
	}
	
}