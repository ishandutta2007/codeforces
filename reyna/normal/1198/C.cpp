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
vector<pair<int, int>> adj[N];
int match[N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < 3 * n; ++j) match[j] = -1, adj[j].clear();
		for (int j = 0; j < m; ++j) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			adj[u].pb(mp(v, j));
			adj[v].pb(mp(u, j));
		}
		vector<int> all;
		for (int v = 0; v < 3 * n; ++v) {
			if (match[v] == -1) {
				for (auto e : adj[v]) if (match[e.first] == -1) {
					match[e.first] = v;
					match[v] = e.first;
					all.pb(e.second);
					break;
				}
			}
		}
		if (all.size() >= n) {
			cout << "Matching\n";
			for (int j = 0; j < n; ++j) cout << all[j] + 1 << ' ';
			cout <<'\n';
		} else {
			cout << "IndSet\n";
			int cnt = 0;
			for (int j = 0; j < 3 * n && cnt < n; ++j)
				if (match[j] == -1) {
					++cnt;
					cout << j + 1 << ' ';
				}
			cout << '\n';
		}
		
	}
}