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
vector<pair<int, int>> moves0, moves1;
int n, m, px[N], py[N], qx[N], qy[N], sv[N];
int cur[N][N], mark[N][N];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
void move(vector<pair<int, int>> &to_move, int x, int y) {
	to_move.pb(mp(x, y));
	swap(cur[x / n][x % n], cur[y / n][y % n]);
}
int d[N * N], q[N * N], par[N * N];
int dfs(int i, int j, int look, vector<pair<int, int>> &to_move) {
	/*if (look == -1 && cur[i][j] >= 0) {
		return 1;	
	}
	if (look != -1 && cur[i][j] == look) {
		return 1;
	}
	if (cur[i][j] == -2) return 0;
	if (cur[i][j] >= 0) return 0;
	if (mark[i][j]++) return 0;
	for (int d = 0; d < 4; ++d) {
		int x = i + dx[d], y = j + dy[d];
		if (x >= 0 && x < n && y >= 0 && y < n) {
			if (dfs(x, y, look, to_move)) {
				move(to_move, x * n + y, i * n + j);
				return 1;
			}
		}
	}
	*/
	memset(d, 63, sizeof d);
	memset(par, -1, sizeof par);
	int h = 0, t = 0;
	q[t++] = i * n + j;
	d[i * n + j] = 0;
	while (h != t) {
		int cur = q[h++];
		int i = cur / n, j = cur % n;
		for (int dd = 0; dd < 4; ++dd) {
			int x = i + dx[dd], y = j + dy[dd];
			if (x >= 0 && x < n && y >= 0 && y < n) {
				int id = x * n + y;
				if (d[id] > d[cur] + 1) {
					d[id] = d[cur] + 1;
					par[id] = cur;
					if (::cur[x][y] == -1) {
						q[t++] = id;	
					}
				}
			}
		}
	}
	int pos = 0;
	if (look == -1) {
		int mn = 1e9, mnpos = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (cur[i][j] >= 0 && d[i * n + j] < mn)
					mn = d[i* n + j], mnpos = i * n + j;
		pos = mnpos;
	} else {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (cur[i][j] == look)
					pos = i * n + j;
	}
	while (pos != -1) {
		int last = par[pos];
		if (last != -1) {
			move(to_move, pos, last);
		}
		pos = last;
	}
}
int lastsv[N];
void get_moves(vector<pair<int, int>> &to_move, int s) {
	for (int col = 0; col < m; ++col) {
//		memset(mark, 0, sizeof mark);
		dfs(0, col, -1, to_move);
		sv[col] = cur[0][col];
		cur[0][col] = -2;
	}
	for (int col = 0; col < m; ++col) {
		cur[0][col] = sv[col];
	}
	if (s == 0) return;
	for (int col = 0; col < m; ++col) if (cur[0][col] != lastsv[col]) {
		int pos = -1;
		for (int j = 0; j < m; ++j)
			if (cur[0][j] == lastsv[col])
				pos = j;
		assert(pos != -1);
//		memset(mark, 0, sizeof mark);
		dfs(min(2, n - 1), pos, lastsv[col], to_move);
//		memset(mark, 0, sizeof mark);
		dfs(0, pos, cur[0][col], to_move);
//		memset(mark, 0, sizeof mark);
		dfs(0, col, lastsv[col], to_move);
	}
}
int main() {
	cin >> n >> m;
	for (int j = 0; j < m; ++j)
		cin >> px[j] >> py[j], --px[j], --py[j];
	for (int j = 0; j < m; ++j) 
		cin >> qx[j] >> qy[j], --qx[j], --qy[j];
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	memset(cur, -1, sizeof cur);
	memset(sv, -1, sizeof sv);
	for (int j = 0; j < m; ++j)
		cur[px[j]][py[j]] = j;
	get_moves(moves0, 0);
	memcpy(lastsv, sv, sizeof sv);
	memset(cur, -1, sizeof cur);
	memset(sv, -1, sizeof sv);
	for (int j = 0; j < m; ++j)
		cur[qx[j]][qy[j]] = j;
	get_moves(moves1, 1);
	reverse(ALL(moves1));
	cout << (int) moves0.size() + (int) moves1.size() << endl;
	assert(moves0.size() + moves1.size() < 10800);
	for (auto x : moves0) {
		int a = x.first, b = x.second;
		cout << a / n + 1 << ' ' << a % n + 1 << ' ' << b / n + 1 << ' ' << b % n + 1 << '\n';
	}
	for (auto x : moves1) {
		int b = x.first, a = x.second;
		cout << a / n + 1 << ' ' << a % n + 1 << ' ' << b / n + 1 << ' ' << b % n + 1 << '\n';
	}
	
}