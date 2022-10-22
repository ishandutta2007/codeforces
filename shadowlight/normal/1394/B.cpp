#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 10;

bool not_edge[N][N][N][N];
bool edges[N * N][N * N];
int cnt;

int n, m, k;

bool increase(vector<int> &t) {
	for (int i = t.size() - 1; i >= 0; --i) {
		if (t[i] < i) {
			++t[i];
			return true;
		}
		t[i] = 0;
	}
	return false;
}

const int MAXN = 2e5 + 7;

int cntq[MAXN][N][N];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	vector <vector <pair <int, int> > > gr(n), rgr(n);
	vector <int> deg(n, 0);
	for (int i = 0; i < m; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		--v, --u;
		++deg[v];
		gr[v].pb({w, u});
		rgr[u].pb({w, v});
	}
	vector <map <int, int> > num(n);
	for (int i = 0; i < n; ++i) {
		sort(gr[i].begin(), gr[i].end());
		for (int j = 0; j < (int) gr[i].size(); ++j) {
			cntq[gr[i][j].y][deg[i]][j]++;
		}
	}

	for (int i = 0; i < n; ++i) {
		int numv = 0;
		for (auto e : gr[i]) {
			int v = deg[i];
			for (int u = 0; u < k; ++u) {
				for (int numu = 0; numu < u; ++numu) {
					if (cntq[e.y][u][numu] && (v != u || numv != numu)) {
						not_edge[v][numv][u][numu] = true;
					}
				}
			}
			if (cntq[e.y][v][numv] >= 2) {
				not_edge[v][numv][v][numv] = true;
			}
			numv++;
		}
	}

	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < i; ++k) {
				if (j != k) {
					not_edge[i][j][i][k] = true;
				}
			}
		}
	}

	map <pair <int, int>, int> numq;
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < i; ++j) {
			numq[{i, j}] = cnt++;
		}
	}
	vector <ll> masks(cnt, 0);

	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int a = 1; a <= k; ++a) {
				for (int b = 0; b < a; ++b) {
					if (not_edge[i][j][a][b]) {
						//cout << "NOT EDGE: " << i << " " << j << " " << a << " " << b << endl;
						continue;
					}
					masks[numq[{i, j}]] |= (1LL << numq[{a, b}]);
				}
			}
		}
	}
	vector <int> t(k, 0);

	int res = 0;

	do {
		ll cur_mask = 0, total_mask = (1LL << cnt) - 1;
		for (int i = 0; i < k; ++i) {
			int v = numq[mp(i + 1, t[i])];
			cur_mask |= (1LL << v);
			total_mask &= masks[v];
		}
		int now = (total_mask & cur_mask) == cur_mask;
		res += now;
	} while (increase(t));

	cout << res << endl;

}