#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N=1010;
vector<int>g[N];
vector<int>gr[N];

const int mod = 998244353;

vector<int> ord;
bool used[N];

void ts(int u) {
	if (used[u]) 
		return;
	used[u] = true;
	for(int v : g[u])
		ts(v);
	ord.push_back(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; ++i) g[i].clear(), gr[i].clear();
		vector<nagai>a(n);
		for(auto& x : a)cin >> x;
		for(int i = 0; i < m; ++i) {
			 int a, b;
			 cin >> a >> b;
			 --a, --b;
			 g[a].push_back(b);
			 gr[b].push_back(a);
		}
		int res = -1;
		int sim_time = n + 1;
		for(int i = 0; i < sim_time; ++i) {
			vector<int> good;
			for(int v = 0; v < n; ++v)
				if (a[v] > 0) good.push_back(v);
			if (good.size() == 0) {
				res = i;
				break;
			}
			for(int v : good) {
				--a[v];
				for(int u : g[v]) 
					++a[u];
			}
		}
		if (res != -1) {
			 cout << res << '\n';
			 continue;
		}
		if (count(a.begin(), a.end(), 0) == n) {
			 cout << sim_time << '\n';
			 continue;
		}
		ord.clear();
		fill(used, used + n, false);
		for(int i = 0; i < n; ++i) {
			if (!used[i])
				ts(i);
		}
		reverse(ord.begin(),ord.end());
		vector<nagai> time0(n, -1);
		for(int v : ord) {
			nagai tot = a[v];
			for(int u : gr[v]) {
				tot += time0[u];
			}
			time0[v] = tot % mod;
		}
		cout << (time0[ord.back()] + sim_time) % mod << '\n';
	}
}