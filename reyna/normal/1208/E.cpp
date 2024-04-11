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
int a[N], sum[N], best[N], pre[N], suf[N], q[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int m, w;
	cin >> m >> w;
	while (m--) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) cin >> a[j];
		if (n * 2 <= w) {
			suf[n] = pre[0] = -1e18;
			for (int j = 0; j < n; ++j) pre[j + 1] = max(pre[j], a[j]);
			for (int j = n - 1; j >= 0; --j) suf[j] = max(suf[j + 1], a[j]);
			int l = 0;
			while (l < n) {
				int b = pre[l + 1];
				if (l + n < w) b = max(b, 0LL);
				sum[l] += b;
				sum[l + 1] -= b;
				++l;
			}
			int r = w - 1, cnt = n - 1;
			while (r >= w - n) {
				int b = suf[cnt];
				if (r >= n) b = max(b, 0LL);
				sum[r] += b;
				sum[r + 1] -= b;
				--r;
				--cnt;
			}
			int mx = max(0LL, pre[n]);
			sum[l] += mx;
			sum[r + 1] -= mx;
		} else {
			int h = 0, t = 0, len_most = w - n + 1;
			for (int cur = 0; cur < w; ++cur) best[cur] = 0; 
			for (int cur = 0; cur < w; ++cur) {
				if (cur < n) {
					while (t - h > 0 && a[q[t - 1]] <= a[cur]) --t;
					q[t++] = cur;
				}
				if (cur >= len_most) {
					while (t - h > 0 && q[h] <= cur - len_most) ++h;	
				}
				best[cur] = a[q[h]];
			}
			for (int cur = 0; cur < w; ++cur) {
				if (cur + n < w) {
					best[cur] = max(best[cur], 0LL);
				}
				if (cur >= n) {
					best[cur] = max(best[cur], 0LL);
				}
				sum[cur] += best[cur];
				sum[cur + 1] -= best[cur];
			}
		}
	}
	for (int j = 1; j < w; ++j) sum[j] += sum[j - 1];
	for (int j = 0; j < w; ++j)
		cout << sum[j] << ' ';
	cout << '\n';
}