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
struct edge { int v; ll w; };

const int MOD = 1e9 + 7;
double EPS = 1e-10;
ll INF = LLONG_MAX / 10;

vector<ll> dijkstra(int N, vector<vector<edge> >& G, int s) {
	vector<ll> d(N, INF); d[s] = 0;
	priority_queue<ll_i, vector<ll_i>, greater<ll_i> > pq;
	pq.push(ll_i(0, s));
	while (pq.size()) {
		ll_i p = pq.top(); pq.pop();
		int u = p.second;
		if (p.first > d[u]) continue;
		for (edge e: G[u])
			if (d[e.v] > d[u] + e.w) {
				d[e.v] = d[u] + e.w;
				pq.push(ll_i(d[e.v], e.v));
			}
	}
	return d;
}

int main() {
	int H, W, N; cin >> H >> W >> N;
	vector<int> y(N), x(N);
	rep(i, N) cin >> y[i] >> x[i], y[i]--, x[i]--;
	int s, t = -1;
	rep(i, N) if (!y[i] && !x[i]) s = i;
	rep(i, N) if (y[i] == H - 1 && x[i] == W - 1) t = i;
	vector<vector<i_i> > row(H), col(W);
	rep(i, N) row[y[i]].pb(i_i(x[i], i)), col[x[i]].pb(i_i(y[i], i));
	vector<int> us, vs, ws;
	for (vector<i_i> a: row) {
		sort(a.begin(), a.end());
		for (int k = 0; k + 1 < a.size(); k++)
			if (a[k + 1].first - a[k].first == 1)
				us.pb(a[k].second), vs.pb(a[k + 1].second), ws.pb(0);
	}
	for (vector<i_i> a: col) {
		sort(a.begin(), a.end());
		for (int k = 0; k + 1 < a.size(); k++)
			if (a[k + 1].first - a[k].first == 1)
				us.pb(a[k].second), vs.pb(a[k + 1].second), ws.pb(0);
	}
	rep(i, N) {
		if (y[i] - 1 >= 0) us.pb(i), vs.pb(N + y[i] - 1), ws.pb(1);
		us.pb(i), vs.pb(N + y[i]), ws.pb(1);
		if (y[i] + 1 < H) us.pb(i), vs.pb(N + y[i] + 1), ws.pb(1);
	}
	rep(i, N) {
		if (x[i] - 1 >= 0) us.pb(i), vs.pb(N+H + x[i] - 1), ws.pb(1);
		us.pb(i), vs.pb(N+H + x[i]), ws.pb(1);
		if (x[i] + 1 < W) us.pb(i), vs.pb(N+H + x[i] + 1), ws.pb(1);
	}
	vector<vector<edge> > G(N + H + W);
	rep(k, us.size()) G[us[k]].pb(edge{vs[k], ws[k]}), G[vs[k]].pb(edge{us[k], ws[k]});
	vector<ll> d = dijkstra(N + H + W, G, s);
	ll ans;
	if (t == -1) ans = min(d[N + H - 1], d[N+H + W - 1]);
	else ans = d[t];
	if (ans == INF) cout << -1 << endl;
	else cout << (ans + 1) / 2 << endl;
}