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
const int N = (int) 2e6 + 6, mod = (int) 0, oo = 1e11 + 100;
int best[N], pre[N], suf[N];
vector<pair<int, int>> arrive[N], depart[N];
int32_t main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int j = 0; j < m; ++j) {
		int d, f, t, c;
		cin >> d >> f >> t >> c;
		if (f == 0) {
			depart[d].push_back(mp(--t, c));
		} else {
			arrive[d].push_back(mp(--f, c));
		}
	}
	{
		for (int j = 0; j < n; ++j) best[j] = oo;
		int sum = n * oo;
		for (int day = 0; day < N; ++day) {
			for (auto x : arrive[day]) {
				int dif = max(0LL, best[x.first] - x.second);	
				best[x.first] = min(best[x.first], x.second);
				sum -= dif;
			}
			pre[day] = sum;
		}
	}
	{
		for (int j = 0; j < n; ++j) best[j] = oo;
		int sum = n * oo;
		for (int day = N - 1; day >= 0; --day) {
			for (auto x : depart[day]) {
				int dif = max(0LL, best[x.first] - x.second);	
				best[x.first] = min(best[x.first], x.second);
				sum -= dif;
			}
			suf[day] = sum;
		}
	}
	int res = oo;
	for (int day = 0; day < N - k - 1; ++day) {
		res = min(res, pre[day] + suf[day + k + 1]);
	}
	if (res >= oo) {
		res = -1;	
	}
	cout << res << '\n';
}