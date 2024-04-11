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

bool dfs(int v, int p, int h) {
	if (gr[v].size() == 1 && h % 2) {
		return false;
	}
	for (int u : gr[v]) {
		if (u == p) continue;
		if (!dfs(u, v, h + 1)) {
			return false;
		}
	}
	return true;
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	gr.resize(n);

	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	int max_diff = n - 1;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int v : gr[i]) {
			if (gr[v].size() == 1) ++cnt;
		}
		if (cnt) {
			max_diff -= cnt - 1;
		}
	}
	int min_diff = 0;
	for (int i = 0; i < n; i++) {
		if (gr[i].size() > 1) continue;
		min_diff = (dfs(i, -1, 0) ? 1 : 3);
		break;
	}
	cout << min_diff << " " << max_diff << "\n";
}