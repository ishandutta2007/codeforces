#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int solve(int N, int M, vector<int> L, vector<int> S, vector<int> C) {
	int level = 0;
	while ((1 << level) <= N) ++level;
	vector<vector<int> > dp(M, vector<int>(2 << level, -inf));
	for (int j = 0; j <= level; ++j) {
		dp[0][1 << j] = 0;
	}
	int ans = 0;
	for (int i = N - 1; i >= 0; --i) {
		vector<int> ndp(1 << level, -inf);
		for (int j = 0; j <= L[i]; ++j) {
			int nlevel = max(level - (L[i] - j), 0);
			for (int k = 1 << nlevel; k < 2 << nlevel; ++k) {
				if (dp[j][k] == -inf) continue;
				int bit = k - (1 << nlevel), profit = dp[j][k] - S[i] + C[L[i]];
				for (int l = 0; l < nlevel; ++l) {
					if ((bit >> l) & 1) {
						profit += C[L[i] + l + 1];
					}
					else {
						break;
					}
				}
				++bit;
				ndp[bit] = max(ndp[bit], profit);
				ans = max(ans, profit);
			}
		}
		for (int j = 0; j < 1 << level; ++j) {
			dp[L[i]][j + (1 << level)] = max(dp[L[i]][j + (1 << level)], ndp[j]);
		}
		for (int j = (1 << level) - 1; j >= 1; --j) {
			dp[L[i]][j] = max(dp[L[i]][j * 2], dp[L[i]][j * 2 + 1]);
		}
	}
	return ans;
}
int solve_easy(int N, int M, vector<int> L, vector<int> S, vector<int> C) {
	int ans = 0;
	for (int i = 0; i < 1 << N; ++i) {
		vector<int> seq;
		vector<int> g(N + M);
		int profit = 0;
		for (int j = 0; j < N; ++j) {
			if ((i >> j) & 1) {
				seq.push_back(L[j]);
				profit += C[L[j]] - S[j];
				++g[L[j]];
			}
		}
		bool decreasing = true;
		for (int j = 1; j < seq.size(); ++j) {
			if (seq[j - 1] < seq[j]) {
				decreasing = false;
			}
		}
		if (!decreasing) continue;
		for (int j = 0; j < N + M; ++j) {
			if (g[j] >= 2) {
				profit += (g[j] / 2) * C[j + 1];
				g[j + 1] += g[j] / 2;
				g[j] %= 2;
			}
		}
		ans = max(ans, profit);
	}
	return ans;
}
#include <random>
#include <string>
mt19937 mt(2003072002);
int rand_rng(int l, int r) {
	uniform_int_distribution<int> p(l, r - 1);
	return p(mt);
}
string to_string(vector<int> arr) {
	string res = "[";
	for (int i = 0; i < arr.size(); ++i) {
		if (i) res += ", ";
		res += to_string(arr[i]);
	}
	res += "]";
	return res;
}
void random_gen() {
	const int samples = 1000000;
	int N = 5, M = 10;
	for (int i = 0; i < samples; ++i) {
		vector<int> L(N), S(N), C(N + M);
		for (int j = 0; j < N; ++j) {
			L[j] = rand_rng(0, M);
			S[j] = rand_rng(0, 100);
		}
		for (int j = 0; j < N + M; ++j) {
			C[j] = rand_rng(-99, 100);
		}
		int res1 = solve(N, M, L, S, C);
		int res2 = solve_easy(N, M, L, S, C);
		if (res1 != res2) {
			cout << "Case #" << i << ":" << endl;
			cout << "N = " << N << " / M = " << M << endl;
			cout << "L = " << to_string(L) << endl;
			cout << "S = " << to_string(S) << endl;
			cout << "C = " << to_string(C) << endl;
			cout << "Returns: " << res1 << endl;
			cout << "Answer: " << res2 << endl;
			cout << endl;
		}
	}
}
int main() {
	// random_gen();
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> L(N), S(N), C(N + M);
	for (int i = 0; i < N; ++i) cin >> L[i], --L[i];
	for (int i = 0; i < N; ++i) cin >> S[i];
	for (int i = 0; i < N + M; ++i) cin >> C[i];
	int ans = solve(N, M, L, S, C);
	cout << ans << endl;
	return 0;
}