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
int a[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, need;
	cin >> n >> need;
	need *= 8;
	int k = need / n, res = n;
	if (k > 20) k = 20;
	map<int, int> cnt;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		cnt[a[j]]++;
	}
	vector<pair<int, int>> all;
	for (auto e : cnt) all.pb(e);
	n = (int) all.size();
	int cur_cnt = 0;
	a[n] = 0;
	for (int j = n - 1; j >= 0; --j) {
		a[j] = a[j + 1] + all[j].second;
	}
	for (int l = 0; l < n; ++l) {
		int r = min(n, l + (1 << k));
		res = min(res, cur_cnt + a[r]);
		cur_cnt += all[l].second;
	}
	cout << res << '\n';
}