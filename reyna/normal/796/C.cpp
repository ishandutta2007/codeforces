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
int a[N];
vector<int> adj[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	multiset<int, greater<int>> st;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		st.insert(a[j]);
	}
	for (int j = 1; j < n; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int res = 2e9;
	for (int x = 0; x < n; ++x) {
		st.erase(st.find(a[x]));
		for (int u : adj[x])
			st.erase(st.find(a[u]));
		int mx = ((int) st.size() ? *(st.begin()) + 2 : -2e9);
		mx = max(mx, a[x]);
		st.insert(a[x]);
		for (int u : adj[x])
			mx = max(mx, 1 + a[u]), st.insert(a[u]);
		res = min(res, mx);
	}
	cout << res << endl;
}