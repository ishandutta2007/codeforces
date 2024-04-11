#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 2005;
ll c[MAXN], k[MAXN], x[MAXN], y[MAXN], rep[MAXN];
int n;
vector<int> power;
vector<pair<int, int>> conn;
 
void init() {
	fill(rep, rep + MAXN, -1);
}
 
int find(int u) {
	return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}
 
bool join(int u, int v) {
	u = find(u), v = find(v);
	if(u == v)
		return false;
	rep[v] = u;
	return true;
}
 
struct edge {
	int u, v;
	ll w;
	bool operator< (const edge &o) const { return w < o.w; }
};
vector<edge> edges;
 
ll kruskal() {
	sort(edges.begin(), edges.end());
	ll cost = 0;
	init();
	for(auto e : edges) {
		if(join(e.u, e.v)) {
			if(e.u == 0)
				power.push_back(e.v);
			else
				conn.push_back({e.u, e.v});
			cost += e.w;
		}
	}
	return cost;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		edges.push_back({0, i, c[i]});
	}
	for(int i = 1; i <= n; i++)
		cin >> k[i];
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			edges.push_back({i, j, d * (k[i] + k[j])});
		}
	}
	cout << kruskal() << '\n';
	cout << power.size() << '\n';
	for(auto p : power)
		cout << p << " ";
	cout << '\n';
	cout << conn.size() << '\n';
	for(auto e : conn)
		cout << e.first << " " << e.second << '\n';
	cout << '\n';
}