#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> a;
vector <int> red, blue, sz;
int ared = 0, ablue = 0;
vector <vector <int> > gr;

int res = 0;

void dfs(int v, int p) {
	sz[v] = 1;
	if (a[v] == 1) {
		red[v]++;
	} else if (a[v] == 2) {
		blue[v]++;
	}
	for (int u : gr[v]) {
		if (u == p) continue;
		dfs(u, v);
		red[v] += red[u];
		sz[v] += sz[u];
		blue[v] += blue[u];
	}
	//cout << v << " " << red[v] << " " << blue[v] << "\n";
	if (p != -1) {
		if ((!red[v] && blue[v] == ablue) || (!blue[v] && red[v] == ared)) {
			res++;
		}
	}
}

int main() {
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	a.resize(n, 0);
	red.resize(n, 0);
	blue.resize(n, 0);
	gr.resize(n);
	sz.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			ared++;
		} else if (a[i] == 2) {
			ablue++;
		}
	}
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].push_back(u);
		gr[u].push_back(v);
	}
	dfs(0, -1);
	cout << res << "\n";
}