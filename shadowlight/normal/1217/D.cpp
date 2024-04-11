#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <int> used;
vector <vector <pair <int, int> > > gr;
vector <int> tme;
int timer = 0;

bool dfs(int v) {
	if (used[v] == 1) return true;
	if (used[v] == 2) return false;
	bool can = false;
	used[v] = 1;
	for (auto e : gr[v]) {
		int u = e.first;
		can = max(can, dfs(u));
	}
	used[v] = 2;
	tme[v] = timer++;
	return can;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	used.resize(n, 0);
	gr.resize(n);
	tme.resize(n);
	vector <pair <int, int> > edges;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		edges.push_back({v, u});
		gr[v].push_back({u, i});
	}
	bool can = true;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		if (dfs(i)) {
			can = false;
		}
	}
	if (can) {
		cout << "1\n";
		for (int i = 0; i < m; i++) {
			cout << "1 ";
		}
		cout << "\n";
		return 0;
	}
	cout << "2\n";
	for (int i = 0; i < m; i++) {
		int v = edges[i].first, u = edges[i].second;
		if (tme[v] > tme[u]) {
			cout << "1 ";
		} else {
			cout << "2 ";
		}
	}
	cout << "\n";
}