#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
void run();
 
signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

const int MAXBITS = 64;

int find_shortest_cyc(const vector<vector<int>> &g, int v) {
	int n = len(g);
	vector<int> dist(n, INF), prv(n, -1);
	dist[v] = 0;
	queue<int> q;
	q.push(v);
	int ans = INF;
	while (len(q)) {
		int v = q.front();
		q.pop();
		for (auto &x : g[v]) {
			if (x != prv[v]) {
				cmin(ans, dist[v] + dist[x] + 1);
			}
			if (cmin(dist[x], dist[v] + 1)) {
				prv[x] = v;
				q.push(x);
			}
		}
	}
	return ans;
}

void run() {
	int n;
	cin >> n;
	vector<vector<int>> v(MAXBITS);
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		for (int j = 0; j < MAXBITS; ++j) {
			if (val & 1) {
				v[j].pb(i);
			}
			val >>= 1;
		}
	}
	for (auto &x : v) {
		if (len(x) > 2) {
			cout << 3 << endl;
			return;
		}
	}
	vector<int> crd;
	for (auto &x : v) {
		if (len(x) == 2) {
			crd.pb(x[0]);
			crd.pb(x[1]);
		}
	}
	sort(all(crd));
	crd.resize(unique(all(crd)) - crd.begin());
	if (len(crd) < 3) {
		cout << -1 << endl;
		return;
	}
	n = len(crd);
	vector<vector<int>> g(n);
	for (auto &x : v) {
		if (len(x) != 2) {
			continue;
		}
		int u, v;
		u = lower_bound(all(crd), x[0]) - crd.begin();
		v = lower_bound(all(crd), x[1]) - crd.begin();
		g[u].pb(v);
		g[v].pb(u);
	}
	for (auto &x : g) {
		sort(all(x));
		x.resize(unique(all(x)) - x.begin());
	}
	int ans = INF;
	for (int i = 0; i < n; ++i) {
		cmin(ans, find_shortest_cyc(g, i));
	}
	if (ans == INF) {
		cout << -1 << endl;
		return;
	}
	cout << ans << endl;
}