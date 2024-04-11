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

const int N = (int) 1e6 + 6, mod = (int) 0;
vector<pair<int, int>> ops;
int n, p[N];
void sw(int a, int b) {
	if (abs(a - b) * 2 >= n) {
		ops.pb(mp(a, b));	
	} else {
		if (a > b) swap(a, b);
		if (b < n / 2) {
			sw(a, n - 1);
			sw(b, n - 1);
			sw(a, n - 1);
		} else if (a >= n / 2) {
			sw(a, 0);
			sw(b, 0);
			sw(a, 0);
		} else {
			sw(a, n - 1);
			sw(b, 0);
			sw(0, n - 1);
			sw(a, n - 1);
			sw(b, 0);
		}
	}
}
int mark[N], rev[N];
int main() {
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> p[j], --p[j], rev[p[j]] = j;
	for (int j = 0; j < n; ++j) if (!mark[j] && j != p[j]) {
		int cur = j;
		while (!mark[cur] && !mark[rev[cur]]) {
			mark[cur] = 1;
			sw(cur, p[cur]);
			cur = rev[cur];
		}
	}
	cout << (int) ops.size() << '\n';
	for (auto e : ops)
		cout << e.first + 1 << ' ' << e.second + 1 << '\n';
	
}