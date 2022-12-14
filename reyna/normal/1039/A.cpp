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
const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], max_pos[N], res[N], mark[N], sum[N];;
int32_t main() {
	int n, t;
	cin >> n >> t;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n; ++j) cin >> max_pos[j], --max_pos[j];
	for (int j = 0; j < n; ++j) {
		sum[j + 1]++;
		sum[max_pos[j] + 1]--;
		mark[max_pos[j] + 1] = 1;
	}
	for (int j = 0; j <= n; ++j) if (j >= 1) sum[j] += sum[j - 1];
	for (int j = 0; j < n; ++j) {
		if (mark[j] && sum[j]) {
			cout << "No\n";
			return 0;
		}
	}
	for (int j = 0; j < n - 1; ++j)
		if (max_pos[j] > max_pos[j + 1]) {
			cout << "No\n";
			return 0;
		}
	a[n] = 2e18 - 1;
	for (int j = 0; j < n; ++j) {
		if (sum[j + 1] > 0) {
			res[j] = a[j + 1] + t;	
		} else {
			res[j] = a[j] + t;
		}
		res[j] = max(res[j], 1LL);
		if (j != 0 && res[j] <= res[j - 1]) {
			res[j] = res[j - 1] + 1;
		}
	}
	for (int j = 1; j < n; ++j)
		if (mark[j] && a[j] + t <= res[j - 1]) {
			cout << "No\n";
			return 0;
		}
	cout << "Yes\n";
	for (int j = 0; j < n; ++j) {
		cout << res[j] << ' ';
	}
}