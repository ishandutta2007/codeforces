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

const int N = (int) 1e6 + 6, mod = (int) 0;
int n, o[N];
int a[N], b[N];
int cmp(int x, int y) {
	return a[x] > a[y];		
}
vector<int> solve(int a[N], int b[N]) {
	vector<int> all;
	for (int j = 0; j < n; ++j)
		if (a[j] < b[j])
			all.pb(j);
	sort(ALL(all), cmp);
	return all;	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j] >> b[j];
		--a[j], --b[j];
	}
	vector<int> x = solve(a, b);
	for (int j = 0; j < n; ++j)
		a[j] = n + n - 1 - a[j], b[j] = n + n - 1 - b[j];
	vector<int> y = solve(a, b);
	if ((int) x.size() > (int) y.size()) {
		swap(x, y);	
	}
	cout << (int) y.size() << '\n';
	for (int x : y)
		cout << x + 1 << ' ';
}