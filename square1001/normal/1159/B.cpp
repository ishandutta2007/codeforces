#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	int ans = 1 << 30;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, A[i] / max(i, N - i - 1));
	}
	cout << ans << endl;
	return 0;
}