#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<int> > A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	map<int, vector<pair<int, int> > > d;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			d[A[i][j]].push_back(make_pair(i, j));
		}
	}
	vector<int> row(N), col(M);
	vector<vector<int> > dp(N, vector<int>(M));
	for (pair<int, vector<pair<int, int> > > i : d) {
		vector<pair<int, int> > points = i.second;
		int K = points.size();
		vector<int> permx(K), permy(K);
		for (int i = 0; i < K; ++i) {
			permx[i] = i; permy[i] = i;
		}
		sort(permx.begin(), permx.end(), [&](int j, int k) { return points[j].first < points[k].first; });
		sort(permy.begin(), permy.end(), [&](int j, int k) { return points[j].second < points[k].second; });
		vector<vector<int> > G(K);
		for (int i = 1; i < K; ++i) {
			if (points[permx[i - 1]].first == points[permx[i]].first) {
				G[permx[i - 1]].push_back(permx[i]);
				G[permx[i]].push_back(permx[i - 1]);
			}
			if (points[permy[i - 1]].second == points[permy[i]].second) {
				G[permy[i - 1]].push_back(permy[i]);
				G[permy[i]].push_back(permy[i - 1]);
			}
		}
		vector<bool> vis(K);
		function<int(int)> get_optimal = [&](int pos) {
			int ans = max(row[points[pos].first], col[points[pos].second]) + 1;
			vis[pos] = true;
			for (int i : G[pos]) {
				if (vis[i]) continue;
				ans = max(ans, get_optimal(i));
			}
			return ans;
		};
		function<void(int, int)> update = [&](int pos, int val) {
			dp[points[pos].first][points[pos].second] = val;
			row[points[pos].first] = val;
			col[points[pos].second] = val;
			for (int i : G[pos]) {
				if (dp[points[i].first][points[i].second] != 0) continue;
				update(i, val);
			}
		};
		for (int i = 0; i < K; ++i) {
			if (vis[i]) continue;
			int opt = get_optimal(i);
			update(i, opt);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (j) cout << ' ';
			cout << dp[i][j];
		}
		cout << '\n';
	}
	return 0;
}