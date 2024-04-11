#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<int>> rgraph(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> graph[i][j];
			rgraph[j][i] = graph[i][j];
		}
	}

	vector<bool> used(n);
	function<void(int, vector<vector<int>> const&, vector<int>&)> dfs = [&](int v, vector<vector<int>> const& g, vector<int>& arr) {
		used[v] = true;
		for (int to = 0; to < n; ++to) {
			if (g[v][to] && !used[to]) {
				dfs(to, g, arr);
			}
		}
		arr.push_back(v);
	};

	vector<int> order;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i, graph, order);
		}
	}

	reverse(order.begin(), order.end());

	fill(used.begin(), used.end(), 0);
	vector<vector<int>> comps;
	vector<int> color(n);
	int cnt = 0;
	for (int v : order) {
		if (!used[v]) {
			vector<int> now;
			dfs(v, rgraph, now);
			for (int u : now) {
				color[u] = cnt;
			}
			++cnt;
			comps.push_back(now);
		}
	}

	vector<vector<int>> ngraph(cnt, vector<int>(cnt));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (graph[i][j]) {
				ngraph[color[i]][color[j]] = 1;
			}
		}
	}

	int cy = 0, cz = 100;
	vector<tuple<int, int, int>> obst;
	vector<tuple<int, int, int>> here(n);

	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; j < n * 3; ++j) {
			obst.push_back({j, cy, cz - 1});
			obst.push_back({j, cy - 1, cz});
			obst.push_back({j, cy - 1, cz + 1});
			if (j != i * 3 + 1) {
				obst.push_back({j, cy + 1, cz});
				obst.push_back({j, cy + 1, cz + 1});
			}
		}
		for (int j = cy + 1; j < cnt * 3; ++j) {
			obst.push_back({i * 3 + 1, j, cz - 1});
			obst.push_back({i * 3 + 1 + 1, j, cz});
			obst.push_back({i * 3 + 1 + 1, j, cz + 1});
			if (j % 3 == 0 && ngraph[i][j / 3]) {

			} else {
				obst.push_back({i * 3 + 1 - 1, j, cz});
				obst.push_back({i * 3 + 1 - 1, j, cz + 1});
			}
		}
		for (int j = 0; j < szof(comps[i]); ++j) {
			here[comps[i][j]] = {j, cy, cz};
		}
		cy += 3;
		cz -= 3;
	}

	int minx = INF, maxx = -INF, miny = INF, maxy = -INF, minz = INF, maxz = -INF;

	for (auto [x, y, z] : obst) {
		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
		minz = min(minz, z);
		maxz = max(maxz, z);
	}

	vector<vector<vector<char>>> outp(maxx - minx + 1, vector<vector<char>>(maxy - miny + 1, vector<char>(maxz - minz + 1, '.')));
	for (auto [x, y, z] : obst) {
		outp[x - minx][y - miny][z - minz] = '#';
	}

	for (int i = 0; i < n; ++i) {
		auto [x, y, z] = here[i];
		outp[x - minx][y - miny][z - minz] = '1' + i;
	}

	cout << maxy - miny + 1 << " " << maxx - minx + 1 << " " << maxz - minz + 1 << "\n";

	for (int i = maxz - minz; i >= 0; --i) {
		for (int j = 0; j < maxx - minx + 1; ++j) {
			for (int k = 0; k < maxy - miny + 1; ++k) {
				cout << outp[j][k][i];
			}
			cout << "\n";
		}
		cout << "\n";
	}

	int z = maxz - minz + 1;
	int y = maxy - miny + 1;
	int x = maxx - minx + 1;
	vector<int> visited_inp, visited_outp;
	vector<vector<vector<bool>>> used_outp;
	vector<bool> used_inp;

	function<void(int)> dfs_inp = [&](int v) {
		used_inp[v] = true;
		visited_inp.push_back(v);
		for (int to = 0; to < n; ++to) {
			if (graph[v][to] && !used_inp[to]) {
				dfs_inp(to);
			}
		}
	};

	function<bool(int, int, int)> free = [&](int cx, int cy, int cz) {
		return 0 <= cx && cx < x && 0 <= cy && cy < y && 0 <= cz && cz < z && outp[cx][cy][cz] != '#';
	};

	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	function<void(int, int, int)> dfs_outp = [&](int cx, int cy, int cz) {
		// cerr << cx << " " << cy << " " << cz << endl;
		if ('0' <= outp[cx][cy][cz] && outp[cx][cy][cz] <= '9') {
			visited_outp.push_back(outp[cx][cy][cz] - '1');
		}
		used_outp[cx][cy][cz] = true;
		for (int d = 0; d < 4; ++d) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (free(nx, ny, cz)) {
				int nz = cz;
				while (nz > 0 && free(nx, ny, nz - 1)) {
					--nz;
				}
				if (!used_outp[nx][ny][nz]) {
					dfs_outp(nx, ny, nz);
				}
			} else if (free(nx, ny, cz + 1) && free(cx, cy, cz + 1) && !used_outp[nx][ny][cz + 1]) {
				dfs_outp(nx, ny, cz + 1);
			}
		}
	};

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			for (int k = 0; k < z; ++k) {
				if ('0' <= outp[i][j][k] && outp[i][j][k] <= '9') {
					visited_outp.clear();
					used_outp = vector<vector<vector<bool>>>(x, vector<vector<bool>>(y, vector<bool>(z)));
					dfs_outp(i, j, k);
					visited_inp.clear();
					used_inp = vector<bool>(n);
					dfs_inp(outp[i][j][k] - '1');

					sort(visited_outp.begin(), visited_outp.end());
					sort(visited_inp.begin(), visited_inp.end());
					// if (visited_inp != visited_outp) {
					// 	cerr << outp[i][j][k] << endl;
					// 	for (int ind : visited_outp) {
					// 		cerr << ind + 1 << " ";
					// 	}
					// 	cerr << endl;
					// 	for (int ind : visited_inp) {
					// 		cerr << ind + 1 << " ";
					// 	}
					// 	cerr << endl;
					// }
					assert(visited_inp == visited_outp);
				}
			}
		}
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}