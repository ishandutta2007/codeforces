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

const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
const int INF = INT_MAX / 2;

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
	int N, x; cin >> N >> x;
	x--;
	vector<vector<int> > G(N);
	rep(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].pb(v); G[v].pb(u);
	}
	vector<int> d0 = bfs(N, G, 0), dx = bfs(N, G, x);
	int ma = 0;
	rep(u, N) if (d0[u] > dx[u]) ma = max(ma, d0[u]);
	cout << ma * 2 << endl;
}