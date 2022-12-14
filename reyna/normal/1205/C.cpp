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

const int N = (int) 55, M = N * N, mod = (int) 0;
int n, mark[M], col[M];
vector<pair<int, int>> adj[M];
int ask(int x0, int y0, int x1, int y1) {
	cout << "? " << x0 + 1 << ' ' << y0 + 1 << ' ' << x1 + 1 << ' ' << y1 + 1 << endl;
	int c;
	cin >> c;
	c ^= 1;
	int id0 = x0 * n + y0, id1 = x1 * n + y1;
	adj[id0].push_back(mp(id1, c));
	adj[id1].push_back(mp(id0, c));
	return c;
}
void dfs(int v, int c) {
	if (mark[v]) return;
	mark[v] = 1;
	col[v] = c;
	for (auto e : adj[v]) {
		int u = e.first, cn = e.second;
		dfs(u, cn ^ c);
	}
}
int main() {
	cin >> n;
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n - 2; ++y) {
			int c = ask(x, y, x, y + 2);
		}
	for (int x = 0; x < n - 2; ++x)
		for (int y = 0; y < 2; ++y)
			ask(x, y, x + 2, y);
	ask(0, 0, 1, 1);
	ask(1, 0, 2, 1);
	dfs(0, 1);
	dfs(1, 1);
	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << col[i * n + j];
		cout << endl;
	}
	return 0;
	*/
	int to_change = 0;
	for (int x = 0; x < n - 2; ++x) {
		if (col[x*n + x] != col[(x + 2) * n + x + 2]) {
			int x0 = x, y0 = x + 1;
			int x1 = x + 2, y1 = x + 1;
			int id0 = x0 * n + y0;
			int id1 = x1 * n + y1;
			if (col[(x + 1) * n + x + 1] == col[x * n + x]) {
				if (col[id0] == col[id1]) {
					int c = ask(x, x, x1, y1);
					to_change = col[x * n + x] ^ col[id1] ^ c;	
				} else {
					int c = ask(x0, y0, x + 2, x + 2);
					to_change = col[id0] ^ col[(x + 2) * n + x + 2] ^ c;
				}
			} else {
				if (col[id0] == col[id1]) {
					int c = ask(x0, y0, x + 2, x + 2);
					to_change = col[id0] ^ col[(x + 2) * n + x + 2] ^ c;
				} else {
					int c = ask(x, x, x1, y1);
					to_change = col[x * n + x] ^ col[id1] ^ c;
				}
			}
			break;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if ((i + j) & 1)
				col[i * n + j] ^= to_change;
	cout << "!" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << col[i * n + j];
		cout << endl;	
	}
	
	
}