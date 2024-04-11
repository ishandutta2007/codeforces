#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	vector<int> D(N);
	for (int i = 0; i < N; ++i) {
		D[i] = A[i] - B[i];
	}
	sort(D.begin(), D.end());
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int ptr = lower_bound(D.begin(), D.end(), -D[i] + 1) - D.begin();
		if (ptr <= i) ptr = i + 1;
		ans += N - ptr;
	}
	cout << ans << '\n';
	return 0;
}