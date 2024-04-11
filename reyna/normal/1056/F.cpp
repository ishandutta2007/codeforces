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
#define double long double
const int N = (int) 105, mod = (int) 0;
double odp[N * 10][N], dp[N * 10][N];
int o[N], a[N], p[N];
int cmp(int x, int y) { return a[x] < a[y]; }
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		double c, t;
		cin >> c >> t;
		for (int j = 0; j < n; ++j) cin >> a[j] >> p[j], o[j] = j;
		sort(o, o + n, cmp);
		for (int j = 0; j < N * 10; ++j) for (int i = 0; i < N; ++i) dp[j][i] = 1e18;
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			int j = o[i];
		//	for (int x = 0; x < N * 10; ++x) for (int y = 0; y < N; ++y) odp[x][y] = dp[x][y], dp[x][y] = 1e18;
			for (int score = N * 10 - 1; score >= p[j]; --score) {
				for (int pick = i + 1; pick >= 1; --pick)
					dp[score][pick] = min(dp[score][pick], (dp[score - p[j]][pick - 1] + a[j]) / 0.9);
			}
		}
		int flag = 0;
		for (int score = n * 10; score >= 0; --score) {
			for (int pick = 0; pick <= n; ++pick) {
				if (dp[score][pick] > 1e15) continue;
				double normal_time = dp[score][pick];
				double cur_t = t - 10 * pick;
				if (cur_t < 0) continue;
				if (normal_time <= cur_t) {
					cout << score << endl;
					flag = 1;
					break;
				}

				// normal_time / (1 + c * ct) 
				// ct + normal_time / (1 + c * ct) <= t
				// (1 + c * ct) * ct + normal_time <= t * (1 + c * ct)
				// c * ct^2 + ct * (1 - c * t) + normal_time - t <= 0
				double xa = c, xb = (1 - c * cur_t), xc = normal_time - cur_t;
				double delta = xb * xb - 4 * xa * xc;
				if (delta < 0) {
					continue;
				}
				double p0 = (-xb - sqrt(delta)) / (2 * xa);
				double p1 = (-xb + sqrt(delta)) / (2 * xa);
				if (p0 > p1) swap(p0, p1);
				p1 = min(p1, cur_t);
				if (p1 > 0) {
					cout << score << endl;
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag)
			cout << 0 << endl;
	}
}