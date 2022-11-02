#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M; long long K;
	cin >> N >> M >> K;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	vector<long long> S(N + 1);
	for(int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i] * M - K;
	vector<long long> opt(M, 1LL << 62);
	long long ans = -(1LL << 62);
	for(int i = 0; i <= N; ++i) {
		opt[i % M] = min(opt[i % M], S[i]);
		for(int j = 0; j < M; ++j) {
			int diff = (j - i % M + M) % M;
			ans = max(ans, (S[i] - opt[j] - diff * K) / M);
		}
	}
	cout << ans << endl;
	return 0;
}