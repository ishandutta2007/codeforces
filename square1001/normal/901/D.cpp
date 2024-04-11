#include <vector>
#include <iostream>
#include <functional>
using namespace std;
class edge {
public:
	int to, id; long long cost;
	edge() : to(-1), id(-1), cost(0) {};
	edge(int to_, int id_, long long cost_) : to(to_), id(id_), cost(cost_) {};
};
int main() {
	int N, M;
	cin >> N >> M;
	vector<long long> c(N);
	for (int i = 0; i < N; ++i) {
		cin >> c[i];
	}
	vector<vector<edge> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(edge(b, i, 0));
		G[b].push_back(edge(a, i, 0));
	}
	vector<int> col(N, -1);
	function<long long(int, int, int)> dfs = [&](int pos, int pre, int depth) {
		col[pos] = depth % 2;
		long long sum = 0;
		for (edge &e : G[pos]) {
			if (col[e.to] != -1) continue;
			long long res = dfs(e.to, pos, depth + 1);
			e.cost = res;
			sum += e.cost;
		}
		return c[pos] - sum;
	};
	long long rem = dfs(0, -1, 0);
	if (rem == 0) {
		vector<long long> fans(M);
		for (int i = 0; i < N; ++i) {
			for (edge e : G[i]) {
				if (e.cost != 0) fans[e.id] = e.cost;
			}
		}
		cout << "YES\n";
		for (int i = 0; i < M; ++i) {
			cout << fans[i] << '\n';
		}
	}
	else {
		bool found = false;
		for (int i = 0; i < N && !found; ++i) {
			for (edge &e : G[i]) {
				if (col[i] == col[e.to]) {
					found = true;
					--c[i]; --c[e.to];
					col = vector<int>(N, -1);
					long long nrem = dfs(0, -1, 0);
					++c[i]; ++c[e.to];
					e.cost = rem / (rem - nrem);
					col = vector<int>(N, -1);
					c[i] -= e.cost; c[e.to] -= e.cost;
					dfs(0, 1, 0);
					vector<long long> fans(M);
					for (int j = 0; j < N; ++j) {
						for (edge ee : G[j]) {
							if (ee.cost != 0) fans[ee.id] = ee.cost;
						}
					}
					cout << "YES\n";
					for (int j = 0; j < M; ++j) {
						cout << fans[j] << '\n';
					}
					break;
				}
			}
		}
		if (!found) {
			cout << "NO\n";
		}
	}
	return 0;
}