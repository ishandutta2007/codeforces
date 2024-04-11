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

const int N = (int) 0, mod = (int) 0;
vector<vector<int>> all;
void add_cycle(int a, int b, int c) {
	vector<int> cur;
	cur.push_back(a);
	cur.push_back(b);
	cur.push_back(c);
	all.push_back(cur);
}
void add_cycle(int a, int b, int c, int d) {
	vector<int> cur;
	cur.push_back(a);
	cur.push_back(b);
	cur.push_back(c);
	cur.push_back(d);
	all.push_back(cur);
}
void solve4(int a, int b, int c, int d) {
	add_cycle(a, b, c, d);
	add_cycle(a, c, b, d);
	add_cycle(a, b, d, c);
}
void add_cycle(int a, int b, int c, int d, int e) {
	add_cycle(a, b, c);
	add_cycle(a, c, d);
	add_cycle(a, d, e);
	add_cycle(a, e, b);
}
void solve5(int a, int b, int c, int d, int e) {
	add_cycle(e, a, b, c, d);	
	add_cycle(a, c, b, d);
	add_cycle(a, b, d, c);
}
void solve6(int a, int b, int c, int d, int e, int f) {
	add_cycle(f, e, b, c);
	add_cycle(f, e, a, d);
	add_cycle(f, a, b);
	add_cycle(e, c, d);
	for (int j = 0; j < 1; ++j) add_cycle(f, c, e, b), add_cycle(f, d, e, a);
	add_cycle(a, c, b, d);
	add_cycle(a, b, d, c);
}
void solve7(int a, int b, int c, int d, int e, int f, int g) {	
//	if (a >= 0) {
		add_cycle(g, a, b, c, d);
		add_cycle(f, a, c, b, d);
		add_cycle(e, a, b, d, c);
//	}
}
int added[305][305];

int main() {
	int n;
	cin >> n;
	if (n % 4 == 2) {
//		cout << -1 << endl;
//		return 0;
	}
	int m = n;
	n -= n % 4;
	for (int x = 0; x < n / 2; ++x)
		for (int y = x + 1; y < n / 2; ++y) {
			if (x % 2 == 0 && y == x + 1) {
				continue;	
			}
			for (int j = 0; j < 2; ++j) add_cycle(x << 1 | 0, y << 1 | 0, x << 1 | 1, y << 1 | 1);
		}
	n = m;
	if (n % 4 == 0) 
		for (int x = 0; x < n / 4 - (n % 4 != 0); ++x) {
			solve4(x << 2 | 0, x << 2 | 1, x << 2 | 2, x << 2 | 3);	
		}
	
	if (n % 4 == 1) {
		for (int x = 0; x < n / 4; ++x) {
			solve5(x << 2 | 0, x << 2 | 1, x << 2 | 2, x << 2 | 3, n - 1);	
		}
	} else if (n % 4 == 2) {
		int e = n - 3, f = n - 2, g = n - 1;
		for (int x = 0; x < n / 4; ++x) {
			if (x == 0) {
				solve6(x << 2 | 0, x << 2 | 1, x << 2 | 2, x << 2 | 3, f, g);
			} else {
				int a = x << 2 | 0, b = x << 2 | 1, c = x << 2 | 2, d = x << 2 | 3;
				add_cycle(f, a, b, c, d);	
				add_cycle(g, a, c, b, d);
				add_cycle(a, b, d, c);
			}
		}
	} else if (n % 4 == 3) {
		int e = n - 3, f = n - 2, g = n - 1;
		for (int x = 0; x < n / 4; ++x) {
			solve7(x << 2 | 0, x << 2 | 1, x << 2 | 2, x << 2 | 3, e, f, g);	
		}
		add_cycle(e, f, g);
		add_cycle(e, f, g);
	}
	cout << (int) all.size() << '\n';
	for (auto v : all) {
		cout << (int) v.size() << ' ';
		for (int x : v) cout << x + 1 << ' ';
		for (int j = 0; j < (int) v.size(); ++j) added[v[j]][v[(j + 1) % (int)v.size()]]++;
		cout << '\n';
	}
	return 0;
	cout << endl << endl;
	for (int x = 0; x < n; ++x)
		for (int y = x + 1; y < n; ++y) {
			added[x][y] += added[y][x];
			cout << x << ' ' << y << ' ' << added[x][y] << endl;	
		}
}