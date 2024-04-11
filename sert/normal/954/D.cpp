#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
const int INF = (int)1e9 + 41;
typedef long long ll;

vector<int> cntDist(const vector<vector<int>> &es, int st) {
	vector<int> d(es.size(), INF);
	vector<bool> u(es.size(), false);
	d[st] = 0;	

	for (int i = 1; i < (int)es.size(); i++) {
		int v = -1;
		for (int j = 0; j < (int)es.size(); j++) {
			if (!u[j] && (v == -1 || d[j] < d[v])) v = j;
		}
		if (v == -1) break;
		u[v] = true;
		for (int w : es[v]) {
			d[w] = min(d[w], d[v] + 1);
		}
	}

	return d;
}

void solve() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--;
	t--;
	vector<vector<int>> es(n);
	vector<vector<bool>> u(n, vector<bool>(n, false));
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		u[v1][v2] = u[v2][v1] = true;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	auto ds = cntDist(es, s);
	auto dt = cntDist(es, t);
	int dist = ds[t];
	assert(ds[t] == dt[s]);

	int ans = 0;
	for (int v1 = 0; v1 < n; v1++) {
		for (int v2 = 0; v2 < v1; v2++) {
			if (ds[v1] + 1 + dt[v2] >= dist && ds[v2] + 1 + dt[v1] >= dist && !u[v1][v2]) {
				ans++;
			} 
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 3;
	for (int i = 1; i < T; i++) solve();	
#endif
}