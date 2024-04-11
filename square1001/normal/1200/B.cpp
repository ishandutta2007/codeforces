#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N; long long M, K;
		cin >> N >> M >> K;
		vector<long long> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		bool ok = true;
		for (int i = 0; i < N - 1; ++i) {
			if (A[i] >= A[i + 1] - K) {
				M += A[i] - max(A[i + 1] - K, 0LL);
				A[i] = max(A[i + 1] - K, 0LL);
			}
			else {
				long long diff = max(A[i + 1] - K, 0LL) - A[i];
				if (diff <= M) {
					M -= diff;
					A[i] = max(A[i + 1] - K, 0LL);
				}
				else {
					ok = false;
					break;
				}
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}