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
int cnt[N], a[N], b[N];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int j = 0; j < n; ++j) cin >> a[j] >> b[j];
	for (int cur = 0; cur < n; ++cur) {
		if (s[cur] == '1') {
			for (int j = 0; j < b[cur]; ++j) cnt[j]++;	
		}
		int pr = (s[cur] - '0');
		for (int j = b[cur]; j < N; j += a[cur]) {
			pr ^= 1;
			for (int i = j; i < j + a[cur]; ++i)
				cnt[i] += pr;
		}
	}
	int res = 0;
	for (int j = 0; j < N; ++j) res = max(res, cnt[j]);
	cout << res << endl;
}