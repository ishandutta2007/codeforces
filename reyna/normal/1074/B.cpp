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
int a[N], b[N], par[N];
vector<int> adj[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int u, int v) { par[find(u)] = find(v); }
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		vector<pair<int, int>> ed;
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) adj[j].clear(), par[j] = j;
		for (int j = 0; j < n - 1; ++j) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			ed.pb(mp(u, v));
			adj[u].pb(v);
			adj[v].pb(u);
		}
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		int k1;
		cin >> k1;
		for (int j = 0; j < k1; ++j) {
			int x;
			cin >> x;
			--x;
			a[x] = 1;
		}	
		int k2, flag = 1;
		cin >> k2;
		int one = 0;
		for (int j = 0; j < k2; ++j) {
			int x;
			cin >> x;
			--x;
			b[x] = 1;
			one = x;
		}
		for (auto e : ed) {
			int u = e.x, v = e.y;
			if (!(a[u] ^ a[v])) unite(u, v);
		}
		cout << "B " << one + 1 << endl;
		int x;
		cin >> x;
		--x;
		if (a[x]) {
			cout << "C " << x + 1 << endl;
			continue;
		}
		int p = find(x);
		for (auto e : ed) {
			int u = e.x, v = e.y;
			if (a[u] > a[v]) swap(u, v);
			if (find(u) == p && a[v] == 1) {
				cout << "A " << v + 1 << endl;
				int y;
				cin >> y;
				--y;
				if (b[y]) {
					cout << "C " << v + 1 << endl;
					flag = 0;
					break;
				}
				cout << "C " << -1 << endl;
				flag = 0;
				break;
				
			}
		}
		
	}
}