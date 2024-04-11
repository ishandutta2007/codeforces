#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

const int N = (int)1e5 + 11;
using ll = long long;
const ll Inf = (ll)1e18;

#define fi first
#define se second

vector <pair <int, int> > e[N];
ll f[N];
int p[N];

int main() {
	//ios :: sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		int u, v, w;
		//cin >> u >> v >> w
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}

	fill(f + 1, f + n + 1, Inf); f[1] = 0;
	/*
	set <pair <long long, int> > pq;
	for(int i = 1; i <= n; i ++) pq.insert({f[i], i});
	while(!pq.empty()) {
		auto u = pq.begin() -> second; pq.erase(*pq.begin());
		for(auto i : e[u]) {
			int v = i.fi, w = i.se;
			if(f[u] + w < f[v]) {
				p[v] = u;
				pq.erase({f[v], v});
				f[v] = f[u] + w;
				pq.insert({f[v], v});
			}
		}
	}
	*/

	using pairing_heap = __gnu_pbds :: priority_queue <pair <ll, int>,
		greater <pair<ll, int>>, pairing_heap_tag>;
	pairing_heap pq;
	pairing_heap :: point_iterator it[N];
	for(int i = 1; i <= n; i ++)
		it[i] = pq.push({f[i], i});
	while(!pq.empty()) {
		auto u = pq.top().se; pq.pop();
		for(auto i : e[u]) {
			int v = i.fi, w = i.se;
			if(f[u] + w < f[v]) {
				p[v] = u;
				f[v] = f[u] + w;
				pq.modify(it[v], {f[v], v});
			}
		}
	}


	if(f[n] == Inf) cout << -1 << '\n';
	else {
		vector <int> ans;
		for(int i = n; ; i = p[i]) {
			ans.push_back(i);
			if(i == 1) break;
		}
		reverse(ans.begin(), ans.end());
		for(int x : ans) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}