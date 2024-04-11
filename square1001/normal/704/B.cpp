#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 62;
long long solve(int N, int S, int E, vector<long long> X, vector<long long> A, vector<long long> B, vector<long long> C, vector<long long> D) {
	vector<long long> dp(2 * N + 1, inf);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		vector<long long> ndp(2 * N + 1, inf);
		for (int j = (i > 0 ? 1 : 0); j <= 2 * i; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (k == 1) {
					int threshold = (S < i && i < E ? (S < E ? 1 : 3) : 2);
					if (j < threshold) continue;
				}
				if (k == 2) {
					int threshold = (S < i && i < E ? (S < E ? 3 : 1) : 0);
					if (j < threshold) continue;
				}
				int sjump = (i == E ? 0 : (k & 1 ? 1 : -1));
				int sland = (i == S ? 0 : (k & 2 ? 1 : -1));
				long long cost = 0;
				if (sjump != 0) cost += (sjump == -1 ? C[i] : D[i]);
				if (sland != 0) cost += (sland == -1 ? A[i] : B[i]);
				if (j + sjump + sland < (i + 1 == N ? 0 : 1)) continue;
				ndp[j + sjump + sland] = min(ndp[j + sjump + sland], dp[j] + cost + (i > 0 ? X[i] - X[i - 1] : 0) * j);
			}
		}
		dp = ndp;
	}
	return dp[0];
}
long long solve_easy(int N, int S, int E, vector<long long> X, vector<long long> A, vector<long long> B, vector<long long> C, vector<long long> D) {
	vector<int> perm(N);
	for (int i = 0; i < N; ++i) perm[i] = i;
	long long ans = inf;
	do {
		if (perm.front() != S || perm.back() != E) continue;
		long long sub = 0;
		for (int i = 1; i < N; ++i) {
			if (perm[i - 1] < perm[i]) sub += X[perm[i]] - X[perm[i - 1]] + D[perm[i - 1]] + A[perm[i]];
			else sub += X[perm[i - 1]] - X[perm[i]] + C[perm[i - 1]] + B[perm[i]];
		}
		ans = min(ans, sub);
	} while (next_permutation(perm.begin(), perm.end()));
	return ans;
}
#include <random>
mt19937 mt(1903311649);
int main() {
	int N, S, E;
	cin >> N >> S >> E; --S, --E;
	vector<long long> X(N), A(N), B(N), C(N), D(N);
	for (int i = 0; i < N; ++i) cin >> X[i];
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	for (int i = 0; i < N; ++i) cin >> C[i];
	for (int i = 0; i < N; ++i) cin >> D[i];
	long long ans = solve(N, S, E, X, A, B, C, D);
	cout << ans << endl;
	/*
	int N = 6;
	uniform_int_distribution<int> p(1, 10);
	for (int i = 1; i <= 1000; ++i) {
		vector<long long> X(N), A(N), B(N), C(N), D(N);
		int coeff = p(mt);
		for (int j = 0; j < N; ++j) {
			X[j] = j * coeff;
			A[j] = p(mt);
			B[j] = p(mt);
			C[j] = p(mt);
			D[j] = p(mt);
		}
		uniform_int_distribution<int> q(0, N - 1);
		int S = q(mt), E = q(mt);
		while (S == E) S = q(mt), E = q(mt);
		long long res1 = solve(N, S, E, X, A, B, C, D);
		long long res2 = solve_easy(N, S, E, X, A, B, C, D);
		if (res1 != res2) {
			cout << "Case #" << i << ":" << endl;
			cout << "N = " << N << ", S = " << S << ", E = " << E << endl;
			cout << "X:"; for (long long j : X) cout << ' ' << j; cout << endl;
			cout << "A:"; for (long long j : A) cout << ' ' << j; cout << endl;
			cout << "B:"; for (long long j : B) cout << ' ' << j; cout << endl;
			cout << "C:"; for (long long j : C) cout << ' ' << j; cout << endl;
			cout << "D:"; for (long long j : D) cout << ' ' << j; cout << endl;
			cout << "Returns: " << res1 << endl;
			cout << "Answer: " << res2 << endl;
			cout << endl;
		}
	}
	*/
	return 0;
}