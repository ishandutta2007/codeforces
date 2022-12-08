#include <bits/stdc++.h>

using namespace std;

#define maxn 1000010
// #define endl '\n'

int par[21][maxn];
int dep[maxn];
int d1, d2;
int diam;

int walk(int u, int k) {
	for (int i = 20; i >= 0; i--) {
		if (k & (1 << i)) {
			u = par[i][u];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) return lca(v, u);
	int diff = dep[u]-dep[v];
	u = walk(u, diff);
	if (u == v) return u;
	for (int i = 20; i >= 0; i--) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

int getdist(int u, int v) {
	int lc = lca(u, v);
	return dep[u]+dep[v] - 2*dep[lc];
}

void addnode(int v, int p) {
	dep[v] = p == -1 ? 1 : dep[p]+1;
	par[0][v] = p;
	for (int i = 1; i <= 20; i++) {
		if (par[i-1][v] != -1) {
			par[i][v] = par[i-1][par[i-1][v]];
		}
		else {
			par[i][v] = -1;
		}
	}
	if (v <= 4) return; //we handled diam explicitly
	int dist1 = getdist(v, d1);
	int dist2 = getdist(v, d2);
	int od2 = d2;
	if (dist1 > diam) {
		diam =  dist1;
		d2 = v;
	}
	if (dist2 > diam) {
		diam = dist2;
		d1 = v;
		d2 = od2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	d1 = 2;
	d2 = 4;
	diam = 2;
	int q;
	cin >> q;
	int ct = 4;
	int v;
	addnode(1, -1);
	addnode(2, 1);
	addnode(3, 1);
	addnode(4, 1);
	
	while (q--) {
		cin >> v;
		addnode(++ct, v);
		addnode(++ct, v);
		cout << diam << endl;
	}
	cin >> q;
}