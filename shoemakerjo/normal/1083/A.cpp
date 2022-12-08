#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 300010
#define pil pair<int, ll>

int n;
ll w[maxn];
bool marked[maxn];
int subsize[maxn];
int pars[maxn];
vector<pil> adj[maxn];
ll curdist;

ll ans = 0LL;
ll myval[maxn];

ll cmax;
ll curboost;
vector<ll> cvals;

void dfscalc(int u, int p) {
	ans = max(ans, myval[u] + cmax + curboost);

	// cout << "   " << u << ": " << myval[u] << " " << curboost << " " << cmax << endl;
	cvals.push_back(myval[u]);
	for (pil vp : adj[u]) {
		if (marked[vp.first] || vp.first == p) continue;
		myval[vp.first] = myval[u] + w[vp.first] - vp.second;
		dfscalc(vp.first, u);
	}

}

void calc(int u) {
	cmax = 0LL;
	curboost = w[u];
	ans = max(ans, curboost);
	// cmax = max(cmax, curboost);
	myval[u] = 0;

	for (pil vp : adj[u]) {
		if (marked[vp.first]) continue;
		myval[vp.first] = w[vp.first] - vp.second;
		dfscalc(vp.first, u);
		for (ll x : cvals) cmax = max(cmax, x);
		cvals.clear();
	}

}

void dfs(int u, int p = -1) {
	pars[u] = p;
	subsize[u] = 1;
	for (pil vp : adj[u]) {
		if (vp.first == p || marked[vp.first]) continue;
		dfs(vp.first, u);
		subsize[u] += subsize[vp.first];
	}
}

int getcentroid(int u, int sz) {
	dfs(u);
	int cen  = u;
	bool isok = false;
	while (!isok) {
		isok = true;
		for (pil vp : adj[cen]) {
			if (marked[vp.first] || vp.first == pars[cen]) {
				continue;
			}
			if (subsize[vp.first] > sz/2) {
				isok = false;
				cen = vp.first;
				break;
			}
		}
	}
	return cen;
}

void go(int u, int sz) {

	int cen = getcentroid(u, sz);

	// cout << "found centroid " << cen << " : " << sz << endl;
	dfs(cen, -1);
	calc(cen);
	marked[cen] = true;
	for (pil vp : adj[cen]) {
		if (marked[vp.first]) continue;
		go(vp.first, subsize[vp.first]);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}


	int u, v;
	ll c;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v >> c;

		adj[u].push_back(pil(v, c));
		adj[v].push_back(pil(u, c));
	}

	go(1, n);

	cout << ans << endl;

}