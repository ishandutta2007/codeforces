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
const int N = (int) 3e5 + 5, mod = (int) 0;
int a[N], s[N], h, t;
pair<int, int> b[N];
int when(int i, int j) {
	if (i > j) swap(i, j);
	int li = -a[i] * i;
	int lj = -a[j] * j;
	int mi = a[i];
	int mj = a[j];
	return (li - lj + mj - mi + 1) / (mj - mi);
}
int32_t main() {
	int n, fx, fy;
	cin >> n >> fx >> fy;
	for (int j = 0; j < n; ++j) cin >> b[j].first, b[j].second = j;
	sort(b, b + n);
	for (int j = 0; j < n; ++j) a[j] = b[j].first;
	for (int ss = 0; ss <= 1; ++ss) {
		h = t = 0;
		s[t++] = 0;
		for (int j = 1; j < n; ++j) {
			while (t - h > 1 && when(s[h], s[h + 1]) <= j) ++h;
			if ((j - s[h]) * a[s[h]] >= fx && (n - j) * a[j] >= fy) {
				if (ss == 0) {
					cout << "Yes\n";
					cout << j - s[h] << ' ' << (n - j) << '\n';
					for (int i = s[h]; i < j; ++i) cout << b[i].second + 1 << ' ';
					cout << '\n';
					for (int i = j; i < n; ++i) cout << b[i].second + 1 << ' ';
					cout << '\n';
					return 0;
				} else {
					cout << "Yes\n";
					cout << n - j << ' ' << j - s[h] << '\n';
					for (int i = j; i < n; ++i) cout << b[i].second + 1 << ' ';
					cout << '\n';
					for (int i = s[h]; i < j; ++i) cout << b[i].second + 1 << ' ';
					cout << '\n';
					return 0;
				}
			}
			if (a[j] == a[j - 1]) continue;
			while (t - h > 1 && when(s[t - 1], s[t - 2]) >= when(s[t - 2], j)) --t;
			s[t++] = j;
		}
		swap(fx, fy);
	}
	cout << "No\n";
}