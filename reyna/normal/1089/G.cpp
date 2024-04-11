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
int a[7];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int k, s = 0;
		cin >> k;
		for (int j = 0; j < 7; ++j) cin >> a[j], s += a[j];
		int res = 1e9;
		for (int st = 0; st < 7; ++st) {
			for (int ed = st; ed <= 7; ++ed) {
				int sum = 0;
				for (int j = st; j < ed; ++j) sum += a[j];
				if (sum > k) continue;
				if ((k - sum) % s != 0) continue;
				int use = (k - sum) / s;
				int days = use * 7 + (ed - st);
				res = min(res, days);
			}
			for (int ed = 0; ed < st; ++ed) {
				int sum = 0;
				for (int j = st; j < 7; ++j) sum += a[j];
				for (int j = 0; j <= ed; ++j) sum += a[j];
				if (sum > k) continue;
				if ((k - sum) % s != 0) continue;
				int use = (k - sum) / s;
				int days = use * 7 + (7 - st) + (ed + 1);
				res = min(res, days);
			}
		}
		cout << res << '\n';
	}
}