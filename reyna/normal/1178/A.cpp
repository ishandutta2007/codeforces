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
int a[N];
int main() {
	int n;
	cin >> n;
	int sum = 0;
	int alsum = 0;
	vector<int> res;
	cin >> a[0];
	res.pb(0);
	sum += a[0];
	alsum += a[0];
	for (int j = 1; j < n; ++j) {
		cin >> a[j];
		sum += a[j];
		if (a[j] * 2 <= a[0])
			alsum += a[j], res.pb(j);
	}
	if (alsum + alsum > sum) {
		cout << (int) res.size() << '\n';
		for (int x : res) cout << x + 1 << ' ';
	} else {
		cout << 0 << '\n';
	}
	
}