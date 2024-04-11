#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

vector <vector <pair <int, int>>> gr;
vector <int> used;

void dfs(int v, int color = 1) {
	if (used[v]) {
		if (used[v] != color) {
			cout << "NO\n";
			exit(0);
		}
		return;
	}
	used[v] = color;
	for (auto e : gr[v]) {
		dfs(e.x, 3 - color);
	}
}

vector <int> pot;
int n, m;

int res = -1;
int vroot = -1;

bool try_root(int root) {
	queue <pair <int, int>> q;
	pot.clear();
	pot.resize(n, INF);
	pot[root] = 0;

	q.push({root, 0});
	//cout << "ROOT: " << root << "\n";
	while (!q.empty()) {
		auto [v, now] = q.front();
		q.pop();
		//cout << "POT: " << v << " " << now << "\n";
		if (now > pot[v]) continue;
		for (auto [u, c] : gr[v]) {
			//cout << u << " " << pot[v] << " " << pot[u] << " " << c << "\n";
			if (pot[u] > pot[v] + 1) {
				q.push({u, pot[v] + 1});
				pot[u] = pot[v] + 1;
			}
			if (c == -1 && pot[u] > pot[v] - 1) {
				q.push({u, pot[v] - 1});
				pot[u] = pot[v] - 1;
				if (pot[u] < 0) {
					return false;
				}
			}
			/*if (c == 1 && pot[u] < pot[v]) {
				return false;
			}*/
		}
	}
	for (int v = 0; v < n; ++v) {
		for (auto [u, c] : gr[v]) {
			if (abs(pot[u] - pot[v]) > 1) {
				return false;
			}
			if (c == 1 && pot[u] != pot[v] + 1) {
				return false;
			}
			if (c == -1 && pot[u] != pot[v] - 1) {
				return false;
			}
		}
	}
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, pot[i]);
	}
	if (mx != INF && mx > res) {
		res = mx;
		vroot = root; 
	}
	return true;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	gr.resize(n);
	used.resize(n, 0);

	for (int i = 0; i < m; ++i) {
		int v, u, c;
		cin >> v >> u >> c;
		--v, --u;
		gr[v].pb({u, c});
		gr[u].pb({v, -c});
	}

	dfs(0);

	for (int i = 0; i < n; ++i) {
		try_root(i);
	}

	if (res == -1) {
		cout << "NO\n";
		return 0;
	}

	try_root(vroot);
	cout << "YES\n";
	cout << res << "\n";
	for (int x : pot) {
		cout << x << " ";
	}
	cout << "\n";
}