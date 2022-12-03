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
#include <cassert>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef vector<int> vi;
struct edge { int v; ll w; };

const int MOD = 1000000007;
double EPS = 1e-10;
ll INF = INT_MAX;

vector<int> bfs(int N, vector<vector<int> >& G, int s) {
	vector<int> d(N, INF); d[s] = 0;
	queue<int> q; q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : G[u])
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	return d;
}

int main() {
	int N, K; cin >> N >> K;
	vector<vector<int> > G(N);
	vector<i_i> ans(N - 1);
	rep(i, N - 1) {
		int u = max(0, i + 1 - K);
		int v = i + 1;
		G[u].pb(v), G[v].pb(u);
		ans[i] = i_i(u, v);
	}
	vector<int> d = bfs(N, G, N - 1);
	int ma = 0;
	rep(u, N) ma = max(ma, d[u]);
	cout << ma << endl;
	rep(i, N - 1) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}