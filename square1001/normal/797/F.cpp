#include <cmath>
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 61;
vector<long long> transform(vector<long long> v, vector<int> p) {
	int n = v.size();
	vector<long long> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i] = v[p[i]];
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<long long> X(N);
	for (int i = 0; i < N; ++i) cin >> X[i];
	vector<long long> P(M), C(M);
	for (int i = 0; i < M; ++i) cin >> P[i] >> C[i];
	sort(X.begin(), X.end());
	vector<int> perm(M);
	for (int i = 0; i < M; ++i) perm[i] = i;
	sort(perm.begin(), perm.end(), [&](int i, int j) { return P[i] < P[j]; });
	P = transform(P, perm);
	C = transform(C, perm);
	vector<long long> dp(N + 1, inf);
	dp[0] = 0;
	for (int i = 0; i < M; ++i) {
		vector<long long> S(N + 1);
		for (int j = 0; j < N; ++j) {
			S[j + 1] = S[j] + abs(X[j] - P[i]);
		}
		deque<pair<long long, int> > que;
		vector<long long> ndp(N + 1, inf);
		for (int j = 0; j <= N; ++j) {
			while (!que.empty() && que.back().first >= dp[j] - S[j]) {
				que.pop_back();
			}
			que.push_back(make_pair(dp[j] - S[j], j));
			ndp[j] = que.front().first + S[j];
			if (que.front().second == j - C[i]) que.pop_front();
		}
		dp = ndp;
	}
	cout << (dp[N] < inf ? dp[N] : -1) << '\n';
	return 0;
}