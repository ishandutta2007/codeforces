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
int can[N], d[N], sum[N], a[N];
int32_t main() {
	int n;
	cin >> n;
	int s = 0;
	for (int j = 0; j < n; ++j)
		cin >> d[j], s ^= d[j] & 1;
	sort(d, d + n);
	reverse(d, d + n);
	for (int j = 0; j < n; ++j) {
		a[j] = -d[j];
		sum[j + 1] = sum[j] + d[j];
	}
	for (int j = 0; j < n; ++j) {
		int cur_sum = sum[j + 1];
		int k = j + 1;
		cur_sum -= k * (k - 1);
		int pos = lower_bound(a + j + 1, a + n, -k) - a;
		int other_sum = sum[n] - sum[pos] + (pos - j - 1) * k;
		int needed = cur_sum - other_sum;
//		cerr << " hello " << j << ' ' << needed << ' ' << k<< endl;
		if (needed > 0) {
			if (needed > k) {
				can[0]++;
				can[d[j]]--;
			} else {
				can[0]++;
				can[needed]--;
			}
		} 
	}
	for (int deg = 0; deg <= n; ++deg) {
		int j = lower_bound(a, a + n, -deg) - a - 1;
		while (j + 1 <= n) {
			int cur_sum = sum[j + 1];
			int k = j + 2;
			cur_sum -= k * (k - 1);
			int pos = lower_bound(a + j + 1, a + n, -k) - a;
			int other_sum = sum[n] - sum[pos] + (pos - j - 1) * k;
			cur_sum += deg;
			int needed = cur_sum - other_sum;
			if (needed > 0) {
				can[deg]++;
				can[deg + 1]--;
			} 
			if (pos == n || d[j + 1] != deg) break;
			++j;
		}
	}	
	for (int j = 0; j < n; ++j) {
		int cur_sum = sum[j + 1];
		int k = j + 2;
		cur_sum -= k * (k - 1);
		int pos = lower_bound(a + j + 1, a + n, -k) - a;
		int other_sum = sum[n] - sum[pos] + (pos - j - 1) * k;
		int needed = other_sum - cur_sum;
//			cerr << " hi " << needed << ' ' << pos << ' ' << k << ' ' << other_sum << endl;
		if (needed > 0) {
			if (needed >= d[j] && needed + 1 < N) {
				can[needed + 1]++;
			}
		} else {
			can[d[j]]++;
		}
	}
	for (int j = 1; j <= n; ++j) can[j] += can[j - 1];
	int cnt = 0;
	for (int j = 0; j <= n; ++j) {
		if (can[j] == 0 && (j & 1) == s) {
			cout << j << ' ';
			++cnt;
		}
	}
	if (!cnt) cout << -1 << endl;
}