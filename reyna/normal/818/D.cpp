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
int cnt[N], mark[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, alice;
	cin >> n >> alice;
	set<pair<int, int>> st;
	for (int j = 1; j < (int) 200 * 1000 + 5; ++j) if (j != alice) st.insert(mp(0, j));
	st.insert(mp(0, -1));
	while (n--) {
		int x;
		cin >> x;
		st.erase(mp(cnt[x], (x == alice ? -1 : x)));
		cnt[x]++;
		st.insert(mp(cnt[x], (x == alice ? -1 : x)));
		while ((int) st.size()) {
			auto cur = *(st.begin());
			if (cur.second == -1) break;
			cnt[cur.second] = -1e9;
			st.erase(cur);
		}
	}
	st.erase(st.begin());
	if ((int) st.size() == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << (*(st.begin())).second << endl;
}