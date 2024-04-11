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

const int N = (int) 20, mod = (int) 0;
int valid[N][N], p[N][2], q[N][2];
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) 
		cin >> p[j][0] >> p[j][1];
	for (int j = 0; j < m; ++j)
		cin >> q[j][0] >> q[j][1];
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			int same = 0, cnt = 0;
			for (int i = 0; i <= 1; ++i)
				for (int j = 0; j <= 1; ++j)
					if (p[x][i] == q[y][j])
						++cnt, same = p[x][i];
			if (cnt == 1) {
				valid[x][y] = same;
			}
		}
	}
	int uniq = 0;
	set<int> candidates;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) if (valid[x][y]) {
			set<int> cur;
			for (int i = 0; i < n; ++i) if (valid[i][y]) cur.insert(valid[i][y]);
			for (int i = 0; i < m; ++i) if (valid[x][i]) cur.insert(valid[x][i]);
			if ((int) cur.size() > 1) {
				cout << -1 << endl;
				return 0;
			}
			for (int x : cur) candidates.insert(x);
		}
	}
	if (candidates.size() == 0) {
		cout << -1 << endl;
		return 0;
	}
	if (candidates.size() > 1) {
		cout << 0 << endl;
		return 0;
	}
	cout << *(candidates.begin()) << endl;
}