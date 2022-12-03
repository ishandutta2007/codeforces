#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
#include <unordered_set>
#include <complex>
using namespace std;
 
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };
// typedef complex<double> C;
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

vector<int> bfs(int N, vector<vector<int> >& G, int s) {
	vector<int> d(N, INF); d[s] = 0;
	queue<int> q; q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v: G[u])
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	return d;
}

void dfs(int u, int p, vector<vector<int> >& G, vector<int>& dz, vector<int>& unko) {
	bool leaf = true;
	for (int v: G[u]) if (v != p) leaf = false, dfs(v, u, G, dz, unko);
	if (leaf) unko.pb(dz[u]);
}

int main() {
	int N; cin >> N;
	vector<vector<int> > G(N);
	rep(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].pb(v); G[v].pb(u);
	}
	vector<int> d0 = bfs(N, G, 0);
	int x = 0;
	rep(u, N) if (d0[u] > d0[x]) x = u;
	vector<int> dx = bfs(N, G, x);
	int y = 0;
	rep(u, N) if (dx[u] > dx[y]) y = u;
	vector<int> dy = bfs(N, G, y);
	int D = dx[y], z;
	rep(u, N) {
		if (D % 2 == 0 && dx[u] == D / 2 && dy[u] == D / 2) z = u;
		if (D % 2 == 1 && dx[u] == D / 2 && dy[u] == D / 2 + 1) z = u;
	}
	vector<int> dz = bfs(N, G, z), hoge;
	for (int u: G[z]) {
		vector<int> unko;
		dfs(u, z, G, dz, unko);
		sort(unko.begin(), unko.end());
		unko.erase(unique(unko.begin(), unko.end()), unko.end());
		if (unko.size() >= 2) {
			cout << -1 << endl;
			return 0;
		}
		hoge.pb(unko[0]);
	}
	sort(hoge.begin(), hoge.end());
	hoge.erase(unique(hoge.begin(), hoge.end()), hoge.end());
	if (hoge.size() >= 3) {
		cout << -1 << endl;
		return 0;
	}
	int ans = hoge.front() + hoge.back();
	while (ans % 2 == 0) ans /= 2;
	cout << ans << endl;
}