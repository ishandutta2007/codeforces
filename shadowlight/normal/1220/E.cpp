#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <int> w;
vector <vector <int> > gr;
int s;
int n, m;

vector <bool> can_up;
vector <int> used;
vector <ll> resd, resu;
int timer = 0;

void dfs(int v, int p = -1) {
	if (used[v]) return;
	used[v] = 1;
	resd[v] = w[v], resu[v] = w[v];
	ll mxu = 0, mxd = 0;
	for (int u : gr[v]) {
		if (u == p) continue;
		if (!used[u]) {
			dfs(u, v);
			if (can_up[u]) {
				can_up[v] = true;
				resu[v] += resu[u];
				resd[v] += resu[u];
				mxu = max(mxu, resd[u] - resu[u]);
			} else {
				mxd = max(mxd, resd[u]);
			}
		} else {
			can_up[v] = true;
		}
	}
	//cout << v + 1 << " " << can_up[v] << " " << resu[v] << " " << resd[v] << "\n";
	resd[v] += max(mxu, mxd);
	used[v] = 2;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	w.resize(n);
	gr.resize(n);
	resd.resize(n, 0), resu.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].push_back(u);
		gr[u].push_back(v);
	}
	cin >> s;
	s--;
	used.resize(n, 0);
	can_up.resize(n, false);
	dfs(s);
	cout << max(resd[s], resu[s]) << "\n";
}