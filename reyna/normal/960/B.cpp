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

const int N = (int) 1e3 + 3, mod = (int) 0;
int a[N], b[N], c[N];
int main() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	int k = k1 + k2;
	for (int j = 0; j < n; ++j) cin >> c[j];
	for (int j = 0; j < n; ++j) cin >> b[j];
	set<pair<int, int>, greater<pair<int, int>>> st;
	for (int j = 0; j < n; ++j) a[j] = abs(b[j] - c[j]), st.insert(mp(a[j], j));
	for (int use = 0; use < k; ++use) {
		auto cur = *(st.begin());
		st.erase(cur);
		if (cur.first == 0) {
			cur.first++;	
		} else {
			cur.first--;
		}
		a[cur.second] = cur.first;
		st.insert(cur);
	}
	long long res = 0;
	for (int j = 0; j < n; ++j)
		res += (long long) a[j] * a[j];
	cout << res << endl;
	
}