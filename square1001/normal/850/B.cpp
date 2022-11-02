#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int N, A[500009], pl; long long X, Y, sum[500009];
long long getcost(int l, int r) {
	int pr = lower_bound(A + pl, A + N, r) - A;
	int pm = lower_bound(A + pl, A + pr, r - X / Y - 1) - A;
	long long res = (pm - pl) * X + (1LL * (r - 1) * (pr - pm) - (sum[pr] - sum[pm])) * Y;
	pl = pr;
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> X >> Y;
	for (int i = 0; i < N; ++i) cin >> A[i];
	sort(A, A + N);
	for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
	long long ans = 1LL << 62;
	for (int i = 2; i <= A[N - 1] + 1; ++i) {
		long long s = 0;
		pl = 0;
		for (int j = 0; j < A[N - 1]; j += i) {
			s += getcost(j + 1, j + i + 1);
		}
		ans = min(ans, s);
	}
	cout << ans << endl;
	return 0;
}