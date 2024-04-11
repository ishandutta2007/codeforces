#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector <int> > gr;

int odd = 0;

void dfs(int v, int p, int h) {
	if (h % 2) {
		++odd;
	}
	for (int u : gr[v]) {
		if (u == p) continue;
		dfs(u, v, h + 1);
	}
}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	gr.resize(n);

	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	dfs(0, -1, 0);
	cout << min(odd - 1, n - odd - 1);
}