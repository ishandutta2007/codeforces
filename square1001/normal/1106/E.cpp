#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const long long inf = 1LL << 61;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> S(K), T(K), D(K), W(K);
	vector<vector<int> > G(N + 1);
	for (int i = 0; i < K; ++i) {
		cin >> S[i] >> T[i] >> D[i] >> W[i];
		G[T[i]].push_back(i);
	}
	vector<vector<long long> > dp(N + 2, vector<long long>(M + 1, inf));
	for (int i = 0; i <= M; ++i) dp[N + 1][i] = 0;
	priority_queue<pair<int, pair<int, int> > > que;
	for (int i = N; i >= 0; --i) {
		for (int j : G[i]) {
			que.push(make_pair(W[j], make_pair(D[j], j)));
		}
		while (!que.empty() && S[que.top().second.second] > i) {
			que.pop();
		}
		if (!que.empty()) {
			pair<int, pair<int, int> > u = que.top();
			for (int j = 0; j <= M; ++j) {
				dp[i][j] = dp[u.second.first + 1][j] + u.first;
			}
		}
		else {
			for (int j = 0; j <= M; ++j) {
				dp[i][j] = dp[i + 1][j];
			}
		}
		for (int j = 0; j < M; ++j) {
			dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
		}
	}
	cout << dp[0][0] << endl;
	return 0;
}