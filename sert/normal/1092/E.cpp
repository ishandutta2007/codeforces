#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

vector<int> es[N];
bool u[N];
int par[N];
int dist[N];
vector<pair<int, int>> comp;

int bfs(int v, int n) {
	for (int i = 0; i < n; i++) {
		par[i] = -1;
		dist[i] = -1;
	}

	queue<int> q;
	q.push(v);
	dist[v] = 0;

	while (!q.empty()) {
		v = q.front();
		u[v] = true;
		q.pop();

		for (int w: es[v]) {
			if (dist[w] == -1) {
				dist[w] = dist[v] + 1;
				q.push(w);
				par[w] = v;
			}
		}
	}

	return v;
}

void go(int v, int n) {
	int b = bfs(v, n);
	int a = bfs(b, n);

	int tm = dist[a] / 2;
	int c = a;
	for (int i = 0; i < tm; i++) {
		c = par[c];
	}
	comp.emplace_back(dist[a], c);
}

inline int d2u(int x) {
	return (x + 1) / 2;
}

void solve() {
	comp.clear();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		es[i].clear();
		u[i] = false;
	}

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	//cerr << "read" << endl;

	for (int i = 0; i < n; i++) {
		if (u[i]) continue;
		go(i, n);
	}

	//cerr << "go " << comp.size() << endl;	

	sort(comp.rbegin(), comp.rend());
	int ans = comp[0].first;
	if ((int)comp.size() > 1) ans = max(ans, d2u(comp[0].first) + d2u(comp[1].first) + 1);
	if ((int)comp.size() > 2) ans = max(ans, d2u(comp[1].first) + d2u(comp[2].first) + 2);

	cout << ans << "\n";
	for (int i = 1; i < (int)comp.size(); i++) {
		cout << comp[0].second + 1 << " " << comp[i].second + 1 << "\n"; 
	}
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}