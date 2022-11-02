#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<long long> A(N), B(N);
	vector<int> perm(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
		perm[i] = i;
	}
	sort(perm.begin(), perm.end(), [&](int i, int j) { return A[i] - B[i] > A[j] - B[j]; });
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += A[perm[i]] * i + B[perm[i]] * (N - i - 1);
	}
	cout << ans << endl;
	return 0;
}