#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<long long> A(N), B(M);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < M; ++i) cin >> B[i];
	long long pl = *max_element(A.begin(), A.end());
	long long pr = *min_element(B.begin(), B.end());
	if (pl > pr) {
		cout << -1 << endl;
	}
	else {
		long long ans = 0;
		for (int i = 0; i < N; ++i) {
			ans += A[i];
		}
		ans *= M;
		sort(A.begin(), A.end(), greater<long long>());
		int cnt = 0;
		for (int i = 0; i < M; ++i) {
			if (B[i] == pl) continue;
			ans += B[i] - A[cnt++ / (M - 1)];
		}
		cout << ans << endl;
	}
	return 0;
}