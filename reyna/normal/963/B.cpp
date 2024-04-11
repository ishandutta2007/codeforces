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

const int N = (int) 2e5 + 5, mod = (int) 0;
int n, h[N], par[N], mark[N];
vector<int> hv[N], adj[N];
void dfs(int v) {
	hv[h[v]].pb(v);
	for (int u : adj[v]) {
		h[u] = h[v] + 1;
		dfs(u);
	}
}
vector<int> res;
int count(int v) {
	int cnt = 0;
	for (int u : adj[v]) 
		if (!mark[u])
			++cnt;
	if (par[v] >= 0 && !mark[par[v]]) ++cnt;
	return cnt;
}
void cut(int v) {
	res.pb(v);
	mark[v] = 1;
	for (int u : adj[v]) if (!mark[u]) cut(u);
}
int main() {
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int root = 0;
	for (int i = 0; i < n; ++i) {
		cin >> par[i];
		--par[i];
		
		if (par[i] >= 0) {
			adj[par[i]].pb(i);	
		} else {
			root = i;
		}
	}
	dfs(root);
	for (int hs = n; hs >= 0; --hs) {
		for (int v : hv[hs]) {
			if (count(v) % 2 == 0) {
				cut(v);
			}
		}
	}
	for (int x : res) cout << x + 1 << '\n';
}