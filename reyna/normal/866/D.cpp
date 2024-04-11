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
int dp[N], odp[N], a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];	
	}
/*	memset(dp, -63, sizeof dp);
	dp[0] = 0;
	for (int j = 0; j < n; ++j) {
		memcpy(odp, dp, sizeof dp);
		for (int stocks = 0; stocks <= j + 1; ++stocks) {
			if (stocks) dp[stocks] = max(dp[stocks], odp[stocks - 1] - a[j]);
			dp[stocks] = max(dp[stocks], odp[stocks + 1] + a[j]);
		}
		cout << " hello " << j << endl;
		for (int stocks = 0; stocks <= j; ++stocks) {
			cout << dp[stocks + 1] - dp[stocks] << " ^ ";
		}
		cout << endl;
		for (int stocks = 0; stocks <= j + 1; ++stocks) {
			cout << dp[stocks] << ' ';	
		}
		cout << endl;
	}
	cout << endl << endl << dp[0] << endl;
*/	
	multiset<int> st;
	st.insert((int) 1e9);
	long long res = 0;
	for (int j = 0; j < n; ++j) {
		int x = a[j];
		auto p = *st.begin();
		if (p <= x) {
			res += x - p;
		}
		st.insert(x);
		st.insert(x);
		st.erase(st.begin());
	}
	cout << res << endl;
	
}