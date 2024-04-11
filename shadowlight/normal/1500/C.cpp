#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

const int T = 1507;

vector <vector <int>> gr;
vector <vector <int>> rgr;
vector <bool> good;
vector <int> deg;
vector <bool> used;
vector <int> inc;

int n, m;

void dfs(int v) {
	good[v] = true;
	for (int u : rgr[v]) {
		if (u < m) {
			--deg[u];
			if (!deg[u]) {
				dfs(u);
			}
		} else if (!good[u]) {
			inc[u] = v;
			dfs(u);
		}
	}
}

vector <int> order;

void ord_dfs(int v) {
	if (!good[v] || used[v]) return;
	used[v] = true;
	for (int u : gr[v]) {
		if (inc[v] != -1 && inc[v] != u) continue;
		ord_dfs(u);
	}
	if (v < m) order.pb(v);
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	gr.resize(n + m);
	rgr.resize(n + m);
	good.resize(n + m, false);
	deg.resize(n + m, 0);
	used.resize(n + m, false);
	inc.resize(n + m, -1);

	vector <vector <int>> a(n, vector<int> (m, 0));
	vector <vector <int>> b(n, vector <int> (m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> b[i][j];
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (b[i - 1][j] > b[i][j]) {
				gr[j].pb(m + i);
				rgr[m + i].pb(j);
			} else if (b[i - 1][j] < b[i][j]) {
				gr[m + i].pb(j);
				rgr[j].pb(m + i);
			}
		}
	}

	/*for (int i = 0; i < n + m; ++i) {
		cout << i + 1 << ": ";
		for (int x : gr[i]) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
*/
	for (int i = 0; i < m; ++i) {
		deg[i] = gr[i].size();
	}

	for (int i = 0; i < m; ++i) {
		if (deg[i]) continue;
		dfs(i);
	}
	for (int i = 0; i < n + m; ++i) {
		ord_dfs(i);
	}
	reverse(all(order));

	vector <pair <int, int> > ord(n);
	for (int i = 0; i < n; ++i) {
		ord[i] = {i, i};
	}
	/*for (int i = 0; i < n + m; ++i) {
		cout << good[i] << " ";
	}
	cout << "\n";*/

	for (int pos : order) {
		sort(all(ord), [&](auto x, auto y) {
			if (a[x.x][pos] != a[y.x][pos]) {
				return a[x.x][pos] < a[y.x][pos];
			}
			return x.y < y.y;
		});
		for (int i = 0; i < n; ++i) {
			ord[i].y = i;
		}
	}

	auto c = a;
	for (int i = 0; i < n; ++i) {
		c[i] = a[ord[i].x];
	}

	if (c == b) {
		cout << order.size() << "\n";
		for (int x : order) {
			cout << x + 1 << " ";
		}
		cout << "\n";
		return 0;
	}
	cout << "-1\n";
}