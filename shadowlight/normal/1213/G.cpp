#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, m;

struct Edge {
	int v, u, w;
};

bool operator<(Edge a, Edge b) {
	return a.w < b.w;
}

vector <int> p, r;
vector <int> sz;

ll res = 0;

int get(int v) {
	return (v == p[v] ? v : p[v] = get(p[v]));
}

void uni(int v, int u) {
	v = get(v);
	u = get(u);
	if (v == u) return;
	if (r[v] == r[u]) r[v]++;
	if (r[v] > r[u]) swap(v, u);
	p[v] = u;
	res += sz[v] * (ll) sz[u];
	sz[u] += sz[v];
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector <pair <int, int> > qs(m);
	vector <Edge> edges;
	p.resize(n, 0);
	r.resize(n, 0);
	sz.resize(n, 1);
	iota(p.begin(), p.end(), 0);
	for (int i = 0; i < n - 1; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		edges.push_back({v, u, w});
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		qs[i] = {x, i};
	}
	sort(qs.begin(), qs.end());
	int now = 0;
	vector <ll> ans(m);
	for (int i = 0; i < m; i++) {
		while (now < n - 1 && edges[now].w <= qs[i].first) {
			uni(edges[now].v, edges[now].u);
			now++;
		}
		//cout << edges[now].w << " " << res << "\n";
		ans[qs[i].second] = res;
	}
	for (ll x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}