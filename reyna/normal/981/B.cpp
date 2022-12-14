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
#define int long long
const int N = (int) 0, mod = (int) 0;
map<int, int> cost[2];
int32_t main() {
	int n;
	cin >> n;
	set<int> st;
	while (n--) {
		int x, y;
		cin >> x >> y;
		cost[0][x] = max(cost[0][x], y);
		st.insert(x);
	}
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		cost[1][x] = max(cost[1][x], y);
		st.insert(x);
	}
	int res = 0;
	for (int x : st) {
		res += max(cost[0][x], cost[1][x]);
	}
	cout << res << endl;
}