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
int a[N], b[N], c[N], o[N];
int cmp(int x, int y) {
	return a[x] < a[y];
}
vector<pair<pair<int, int>, int>> ops;
void add_op(int i, int j, int x) {
	c[i] -= x;
	c[j] += x;
	ops.pb(mp(mp(o[i], o[j]), x));
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, res = 0;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> a[j], res += a[j], o[j] = j;
	for (int j = 0; j < n; ++j)
		cin >> b[j], res -= b[j];
	sort(o, o + n, cmp);
	sort(a, a + n);
	sort(b, b + n);
	if (res != 0) {
		cout << "NO\n";
		return 0;
	}
	for (int j = 0; j < n; ++j)
		c[j] = b[j] - a[j];
	set<int> st;
	for (int j = 0; j < n; ++j) {
		if (c[j] > 0) {
			st.insert(j);
		} else {
			while ((int) st.size() && c[j] < 0) {
				int cur = *(st.begin());
				int both = min(c[cur], -c[j]);
				add_op(cur, j, both);
				if (!c[cur]) st.erase(cur);
				if (!c[j]) break;
			}
			if (c[j] < 0) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	cout << (int) ops.size() << '\n';
	for (auto e : ops)
		cout << e.x.x + 1 << ' ' << e.x.y + 1 << ' ' << e.y << '\n';
	
}