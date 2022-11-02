#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

struct edge{
	int to, cost;
	edge() {}
	edge(int _to, int _cost) {
		to = _to, cost = _cost;
	}
};

const int MAXN = 2e5 + 10;
int n;
vector<edge> g[MAXN];

int cycle[MAXN], rcycle[MAXN], topCycle = 0;
int par[MAXN], tin[MAXN], timer = 0;
int used[MAXN];
ll ans[MAXN], fans[MAXN];

int h[MAXN], sz[MAXN];
int fcost[MAXN][2];
int fullCycle = 0;

void buildCost() {
	for (int v = 0; v < n; v++) {
		if (!used[v]) continue;
		int posV = rcycle[v];
		for (auto [to, cost] : g[v]) {
			if (!used[to]) continue;
			int posU = rcycle[to];
			if (posU == posV - 1 || posU - (topCycle - 1) == posV) {
				fcost[posV][0] = cost;
			} else {
				fcost[posV][1] = cost;
			}
		}
	}
}

void dfsCycle(int v, int p) {
	used[v] = true;
	tin[v] = timer++;
	par[v] = p;
	for (auto [to, cost] : g[v]) {
		if (to == p) continue;
		if (!used[to]) {
			dfsCycle(to, v);
		}
	}
}

void findCycle() {
	fill(used, used + n, false);
	dfsCycle(0, -1);
	for (int v = 0; v < n; v++) {
		bool ok = false;
		for (auto [to, cost] : g[v]) {
			if (to == par[v]) continue;
			if (par[to] == v) continue;
			if (tin[v] < tin[to]) swap(v, to);
			while (v != to) {
				cycle[topCycle++] = v;
				v = par[v];
			}
			cycle[topCycle++] = v;
			ok = true;
			break;
		}
		if (ok) break;
	}
	fill(used, used + n, false);
	for (int i = 0; i < topCycle; i++) {
		used[cycle[i]] = true;
	}
	for (int i = 0; i < topCycle; i++) {
		rcycle[cycle[i]] = i;
	}
	buildCost();
}

void dfsBuild(int v, int p) {
	sz[v] = 1;
	fans[v] = 0;
	for (auto [to, cost] : g[v]) {
		if (to == p) continue;
		if (used[to]) continue;
		h[to] = h[v] + cost;
		dfsBuild(to, v);
		sz[v] += sz[to];
		fans[v] += fans[to] + sz[to] * cost;
	}
}

struct myDeque{
	deque<int> cost;
	deque<int> v;
	int fullSz;
	int fullCost;
	ll ans;
	myDeque() {
		cost = {};
		v = {};
		fullCost = 0;
		fullSz = 0;
		ans = 0;
	}
	void addR(int _cost, int _v) {
		ans += (fullCost + _cost) * sz[_v] + fans[_v];
		fullCost += _cost;
		fullSz += sz[_v];
		cost.push_back(_cost);
		v.push_back(_v);
	}
	void delR() {
		int _cost = cost.back();
		int _v = v.back();
		cost.pop_back();
		v.pop_back();
		fullCost -= _cost;
		fullSz -= sz[_v];
		ans -= (fullCost + _cost) * sz[_v] + fans[_v];
	}
	void addL(int _cost, int _v) {
		fullCost += _cost;
		fullSz += sz[_v];	
		ans += fullSz * _cost + fans[_v];
		cost.push_front(_cost);
		v.push_front(_v);
	}
	void delL() {
		int _cost = cost.front();
		int _v = v.front();
		cost.pop_front();
		v.pop_front();
		ans -= fullSz * _cost + fans[_v];
		fullCost -= _cost;
		fullSz -= sz[_v];
	}
	bool empty() {
		return v.empty();
	}
};

void balance(myDeque & L, myDeque & R) {
	while (true) {
		if (!L.empty() && L.fullCost > fullCycle - L.fullCost) {
			int v = L.v.back();
			int pos = rcycle[v];
			L.delR();
			R.addR(fcost[pos][0], v);
		} else if (!R.empty() && R.fullCost > fullCycle - R.fullCost) {
			int v = R.v.back();
			int pos = rcycle[v];
			R.delR();
			L.addR(fcost[pos][1], v);
		} else {
			return;
		}
	}
	assert(false);
}

void makeNxt(myDeque & L, myDeque & R, int pos, int v) {
	if (!R.empty()) {
		R.delL();
	} else {
		L.delR();
	}
	L.addL(fcost[pos][1], v);
}

void buildCycle() {
	for (int i = 0; i < topCycle; i++) {
		dfsBuild(cycle[i], -1);
	}
	myDeque L, R;
	for (int i = 0; i < topCycle; i++) {
		fullCycle += fcost[i][1];
	}
	for (int i = 1; i < topCycle; i++) {
		R.addR(fcost[i][0], cycle[i]);
	}
	for (int i = 0; i < topCycle; i++) {
		balance(L, R);
		ans[cycle[i]] = L.ans + R.ans + fans[cycle[i]];
		if (i + 1 < topCycle) makeNxt(L, R, i, cycle[i]);
	}
}

void dfsSolve(int v, int p) {
	for (auto [to, cost] : g[v]) {
		if (used[to]) continue;
		if (to == p) continue;
		ans[to] += ans[v] + (n - 2 * sz[to]) * cost;
		dfsSolve(to, v);
	}
}

void solveOther() {
	for (int i = 0; i < topCycle; i++) {
		dfsSolve(cycle[i], -1);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		u--;
		v--;
		g[u].push_back({v, cost});
		g[v].push_back({u, cost});
	}
	findCycle();
	buildCycle();
	solveOther();
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}