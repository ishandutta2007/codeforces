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

const int N = (int) 305, mod = (int) 0;
int res[N], a[N], b[N], seen, ch;
int ask(int l, int r) {
	cout << "? " << l + 1 << ' ' << r + 1 << endl;
	int x;
	cin >> x;
	assert(x != -1);
	return x;
}
int main() {
	int n, t;
	cin >> n >> t;
	int t_first = t;
	for (int j = 0; j < n - 1; ++j) {
		int expect_change = 0;
		{
			int cur_t = t;
			int rem_t = 0;
			for (int i = 0; i < j; ++i) rem_t += b[i];
			int ones = (cur_t - rem_t);
			int zeros = (n - j - 1) - ones;
			int change = zeros - ones;
			expect_change = change;
		}
		int witnessed = 0;
		for (int turn = 0; turn < 20; ++turn) {
			int cur_t = t;
			int new_t = ask(j + 1, n - 1);
			if (cur_t == n - new_t) {
				for (int i = 0; i <= j; ++i) b[i] ^= 1;
			} else {
				++witnessed;
				int rem_t = 0;
				for (int i = 0; i <= j; ++i) rem_t += b[i];
				int ones = (cur_t - rem_t);
				int zeros = (n - j - 1) - ones;
				int change = zeros - ones;
				if (change + cur_t != new_t) {
					a[j] = 1;	
				}
			}
			t = new_t;
		}
		if (!witnessed) {
			int cur_t = t;
			if (n - cur_t != cur_t + expect_change) {
				a[j] = 1;
			}
		}
		b[j] ^= a[j];
		seen += a[j];
	}
	memcpy(res, a, sizeof a);
	for (int j = 0; j < n - 1; ++j) t_first -= res[j];
	res[n - 1] = t_first;
	cout << "! ";
	for (int j = 0; j < n; ++j) cout << res[j];
	cout << endl;
}