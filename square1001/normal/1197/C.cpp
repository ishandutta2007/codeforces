#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	vector<int> d(N - 1);
	for(int i = 1; i < N; ++i) d[i - 1] = A[i] - A[i - 1];
	sort(d.begin(), d.end(), [](int i, int j) { return i > j; });
	int ans = A[N - 1] - A[0];
	for(int i = 0; i < K - 1; ++i) ans -= d[i];
	cout << ans << endl;
	return 0;
}