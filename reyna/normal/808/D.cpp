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
int a[N];
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int turn = 0; turn <= 1; ++turn) {
		reverse(a, a + n);
		map<int, int> mp;
		int sum = 0, cursum = 0;
		for (int j = 0; j < n; ++j) sum += a[j];
		for (int j = 0; j < n; ++j) {
			cursum += a[j];
			sum -= a[j];
			mp[a[j]]++;
			if (cursum == sum) {
				cout << "YES\n";
				return 0;
			}
			if (cursum > sum && (cursum - sum) % 2 == 0 && mp[(cursum - sum) / 2]) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}