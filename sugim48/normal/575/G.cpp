#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N, M; cin >> N >> M;
	vector<vector<edge> > G(N);
	while (M--) {
		int a, b, len; scanf("%d%d%d", &a, &b, &len);
		G[a].push_back(edge{b, len});
		G[b].push_back(edge{a, len});
	}
	vector<int> d(N, INT_MAX); d[0] = 0;
	vector<int> prev(N); prev[0] = -1;
	vector<int> a(N);
	vector<i_i> p(N);
	queue<int> q; q.push(0);
	for (;;) {
		queue<int> _q;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i].v, w = G[u][i].w;
				if (d[u] + 1 < d[v]) {
					d[v] = d[u] + 1;
					prev[v] = u;
					p[v] = i_i(w, a[u]);
					_q.push(v);
				}
				else if (d[u] + 1 == d[v] && i_i(w, a[u]) < p[v]) {
					p[v] = i_i(w, a[u]);
					prev[v] = u;
				}
			}
		}
		if (_q.empty()) break;
		vector<int> v;
		while (!_q.empty()) {
			int u = _q.front(); _q.pop();
			q.push(u);
			v.push_back(u);
		}
		int n = v.size();
		vector<i_i> unko(n);
		for (int i = 0; i < n; i++)
			unko[i] = p[v[i]];
		sort(unko.begin(), unko.end());
		unko.erase(unique(unko.begin(), unko.end()), unko.end());
		for (int i = 0; i < n; i++)
			a[v[i]] = lower_bound(unko.begin(), unko.end(), p[v[i]]) - unko.begin();
	}

	vector<int> d0(N, INT_MAX); d0[N - 1] = 0;
	vector<int> prev0(N); prev0[N - 1] = -1;
	q.push(N - 1);
	for (;;) {
		queue<int> _q;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i].v, w = G[u][i].w;
				if (w) continue;
				if (d0[u] + 1 < d0[v]) {
					d0[v] = d0[u] + 1;
					prev0[v] = u;
					_q.push(v);
				}
			}
		}
		if (_q.empty()) break;
		q = _q;
	}
	int _u;
	pair<i_i, int> mini(i_i(INT_MAX, INT_MAX), INT_MAX);
	for (int u = 0; u < N; u++) {
		if (d[u] == INT_MAX || d0[u] == INT_MAX) continue;
		if (make_pair(i_i(d[u], a[u]), d0[u]) < mini) {
			_u = u;
			mini = make_pair(i_i(d[u], a[u]), d0[u]);
		}
	}
	vector<int> ans, ans0;
	string s;
	for (int u = _u; prev[u] != -1; u = prev[u]) {
		ans.push_back(prev[u]);
		s.push_back('0' + p[u].first);
	}
	for (int u = _u; prev0[u] != -1; u = prev0[u])
		ans0.push_back(prev0[u]);
	reverse(ans.begin(), ans.end());
	if (s.empty()) s = "0";
	cout << s << endl;
	cout << ans.size() + 1 + ans0.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << _u << ' ';
	for (int i = 0; i < ans0.size(); i++)
		cout << ans0[i] << ' ';
	cout << endl;
}