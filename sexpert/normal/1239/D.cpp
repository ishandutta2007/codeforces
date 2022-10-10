#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
vector<int> adj[2*MAXN], comps[2*MAXN], sta;
int comp[2*MAXN], ca[2*MAXN], cb[2*MAXN], good[MAXN], tin[2*MAXN], low[2*MAXN], mark[MAXN];
int n, m, dfst, cc;

void dfs(int s) {
	tin[s] = low[s] = ++dfst;
	sta.push_back(s);
	for(auto v : adj[s]) {
		if(!tin[v]) {
			dfs(v);
			low[s] = min(low[s], low[v]);
		}
		else if(!comp[v])
			low[s] = min(low[s], tin[v]);
	}
	if(low[s] == tin[s]) {
		cc++;
		int z;
		do {
			z = sta.back(); sta.pop_back();
			comp[z] = cc;
			ca[cc] += (z <= n);
			cb[cc] += (z > n);
			comps[cc].push_back(z);
		} while(z != s);
		for(auto v : comps[cc])
			for(auto x : adj[v])
				if(comp[x] != cc)
					good[cc] = 0;
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= 2*n; i++) {
		adj[i].clear();
		comps[i].clear();
		low[i] = tin[i] = comp[i] = ca[i] = cb[i] = 0;
		good[i] = 1;
	}
	while(m--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(n + y);
		if(x == y)
			adj[n + y].push_back(x);
	}
	cc = dfst = 0;
	for(int i = 1; i <= n; i++)
		if(!comp[i]) dfs(i);
	for(int c = 1; c <= cc; c++) {
		if(ca[c] == cb[c] && good[c] && ca[c] < n) {
			for(int i = 1; i <= n; i++)
				mark[i] = 0;
			cout << "Yes\n";
			cout << ca[c] << " " << n - ca[c] << '\n';
			for(auto v : comps[c]) {
				if(v <= n)
					cout << v << " ";
				else
					mark[v - n] = 1;
			}
			cout << '\n';
			for(int i = 1; i <= n; i++)
				if(!mark[i])
					cout << i << " ";
			cout << '\n';
			return;
		}
	}
	cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}