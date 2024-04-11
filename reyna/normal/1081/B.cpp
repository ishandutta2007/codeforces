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

const int N = (int) 1e6 + 5, mod = (int) 0;
int a[N], cnt[N], st[N], g[N], cc;
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j], a[j] = n - a[j] - 1, cnt[a[j] + 1]++;
	for (int j = 1; j < N; ++j)
		if (cnt[j] % j != 0) {
			cout << "Impossible\n";
			return 0;
		}
	cout << "Possible\n";
	for (int j = 0; j < n; ++j) {
		if (st[a[j] + 1] > 0) {
			cout << g[a[j] + 1] + 1 << ' ';
			--st[a[j] + 1];
		} else {
			g[a[j] + 1] = cc++;
			cout << g[a[j] + 1] + 1 << ' ';
			st[a[j] + 1] = a[j] + 1;
			--st[a[j] + 1];
		}
	}
	
}