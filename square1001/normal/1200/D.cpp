#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<string> S(N);
	for (int i = 0; i < N; ++i) cin >> S[i];
	vector<vector<int> > sum(N - K + 2, vector<int>(N - K + 2));
	function<void(int, int, int, int)> add = [&](int xa, int ya, int xb, int yb) {
		++sum[xa][ya];
		++sum[xb][yb];
		--sum[xa][yb];
		--sum[xb][ya];
	};
	for (int i = 0; i < N; ++i) {
		int lc = inf, rc = -inf;
		for (int j = 0; j < N; ++j) {
			if (S[i][j] == 'B') {
				lc = min(lc, j);
				rc = max(rc, j);
			}
		}
		if (lc == inf) {
			add(0, 0, N - K + 1, N - K + 1);
		}
		else if (rc - lc <= K - 1) {
			add(max(rc - K + 1, 0), max(i - K + 1, 0), min(lc + 1, N - K + 1), min(i + 1, N - K + 1));
		}
	}
	for (int i = 0; i < N; ++i) {
		int lc = inf, rc = -inf;
		for (int j = 0; j < N; ++j) {
			if (S[j][i] == 'B') {
				lc = min(lc, j);
				rc = max(rc, j);
			}
		}
		if (lc == inf) {
			add(0, 0, N - K + 1, N - K + 1);
		}
		else if (rc - lc <= K - 1) {
			add(max(i - K + 1, 0), max(rc - K + 1, 0), min(i + 1, N - K + 1), min(lc + 1, N - K + 1));
		}
	}
	for (int i = 0; i <= N - K; ++i) {
		for (int j = 0; j <= N - K + 1; ++j) {
			sum[i + 1][j] += sum[i][j];
		}
	}
	for (int i = 0; i <= N - K + 1; ++i) {
		for (int j = 0; j <= N - K; ++j) {
			sum[i][j + 1] += sum[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i <= N - K; ++i) {
		for (int j = 0; j <= N - K; ++j) {
			ans = max(ans, sum[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}