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

const int N = (int) 1e5 + 5, mod = (int) 0;
int fen[4][11][11][N];
int query(int m, int *f) { ++m;
	int res = 0;
	while (m > 0)
		res += f[m], m -= m & -m;
	return res;
}
int query(int l, int r, int *f) {
	return query(r - 1, f) - query(l - 1, f);	
}
void update(int m, int x, int *f) { ++m;
	while (m < N)
		f[m] += x, m += m & -m;
}
map<char, int> rev;
string s;
void add(int pos, int x) {
	int ind = rev[s[pos]];
	for (int len = 1; len <= 10; ++len) {
		update(pos, x, fen[ind][len][pos % len]);	
	}
}
int main() {
	rev['A'] = 0;
	rev['C'] = 1;
	rev['T'] = 2;
	rev['G'] = 3;
	cin >> s;
	for (int j = 0; j < (int) s.size(); ++j)
		add(j, 1);
	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 2) {
			int l, r;
			cin >> l >> r;
			--l;
			string e;
			cin >> e;
			int m = (int) e.size(), res = 0;
			for (int pos = 0; pos < m; ++pos) {
				int ind = rev[e[pos]];
				res += query(l, r, fen[ind][m][(l + pos) % m]);
			}
			cout << res << '\n';
		} else {
			int pos;
			char c;
			cin >> pos >> c;
			--pos;
			add(pos, -1);
			s[pos] = c;
			add(pos, 1);
		}
	}
}