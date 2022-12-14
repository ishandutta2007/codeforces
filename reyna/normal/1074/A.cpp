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
multiset<int> st;
vector<int> blocked;
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		blocked.pb(x);
	}
	for (int j = 0; j < m; ++j) {
		int xl, xr, y;
		cin >> xl >> xr >> y;
		--xl;
		if (!xl) {
			st.insert(xr);	
		}
	}
	sort(ALL(blocked));
	int res = (int) st.size();
	for (int cost = 0; cost <= (int) blocked.size(); ++cost) {
		int nxt = (cost == blocked.size() ? 1000 * 1000 * 1000 : blocked[cost]);
		while ((int) st.size()) {
			auto x = *(st.begin());	
			if (x < nxt) {
				st.erase(st.begin());	
			} else {
				break;
			}
		}
		res = min(res, cost + (int) st.size());
	}
	cout << res << endl;
}