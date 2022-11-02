#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		cin >> N;
		vector<int> C(N);
		for (int i = 0; i < N; ++i) {
			int x;
			cin >> x; --x;
			++C[x];
		}
		vector<int> used(N + 1);
		for (int i = 0; i < N; ++i) {
			++used[C[i]];
		}
		vector<int> A;
		for (int i = 1; i <= N; ++i) {
			if (used[i]) {
				A.push_back(i);
			}
		}
		vector<int> cand;
		for (int i = 2; i <= N + 1; ++i) {
			int t = (A[0] + i - 1) / i;
			if (t * (i - 1) <= A[0]) {
				cand.push_back(i);
			}
		}
		int ans = inf;
		for (int i : cand) {
			bool ok = true;
			int sum = 0;
			for (int j : A) {
				int t = (j + i - 1) / i;
				if (t * (i - 1) > j) {
					ok = false;
					break;
				}
				sum += t * used[j];
			}
			if (ok) {
				ans = min(ans, sum);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}