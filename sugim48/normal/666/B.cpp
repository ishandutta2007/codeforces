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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
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

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int> > G(N);
	while (M--) {
		int u, v; cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
	}
	vector<vector<int> > d(N);
	for (int u = 0; u < N; u++)
		d[u] = bfs(N, G, u);
	vector<vector<i_i> > a(N), b(N);
	for (int u = 0; u < N; u++) {
		priority_queue<i_i, vector<i_i>, greater<i_i> > A, B;
		for (int v = 0; v < N; v++) {
			if (u == v) continue;
			if (d[v][u] != INF) {
				A.push(i_i(d[v][u], v));
				if (A.size() > 3) A.pop();
			}
			if (d[u][v] != INF) {
				B.push(i_i(d[u][v], v));
				if (B.size() > 3) B.pop();
			}
		}
		while (!A.empty()) {
			a[u].push_back(A.top());
			A.pop();
		}
		while (!B.empty()) {
			b[u].push_back(B.top());
			B.pop();
		}
	}
	int ma = 0, _x, _u, _v, _y;
	for (int u = 0; u < N; u++)
		for (int v = 0; v < N; v++) {
			if (u == v || d[u][v] == INF) continue;
			for (i_i p: a[u])
				for (i_i q: b[v]) {
					int x = p.second, y = q.second;
					if (x == v || y == u || x == y) continue;
					int D = d[x][u] + d[u][v] + d[v][y];
					if (D > ma) {
						ma = D;
						_x = x; _u = u; _v = v; _y = y;
					}
				}
		}
	cout << _x + 1 << ' ' << _u + 1 << ' ' << _v + 1 << ' ' << _y + 1 << endl;
}