#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long solve(int N, vector<int> &seq, int limit) {
	int sum = N;
	vector<int> bit(2 * N + 2);
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = sum + 1; j <= 2 * N + 1; j += j & (-j)) ++bit[j];
		sum += (seq[i] <= limit ? 1 : -1);
		for(int j = sum + 1; j >= 1; j -= j & (-j)) ans += bit[j];
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	long long res1 = solve(N, A, M);
	long long res2 = solve(N, A, M - 1);
	cout << res1 - res2 << endl;
	return 0;
}