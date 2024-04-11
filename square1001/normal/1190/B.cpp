#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	long long sum = 0;
	for (int i = 0; i < N; ++i) cin >> A[i], sum += A[i];
	sort(A.begin(), A.end());
	int cnt = 0, ptr = -1;
	for (int i = 1; i < N; ++i) {
		if (A[i] == A[i - 1]) {
			cnt += (A[i] == 0 ? 2 : 1);
			ptr = i;
		}
	}
	if (cnt == 1 && ptr >= 2 && A[ptr - 2] + 1 == A[ptr]) cnt = 2;
	sum -= 1LL * N * (N - 1) / 2;
	cout << (cnt <= 1 && sum % 2 == 1 ? "sjfnb" : "cslnb") << endl;
	return 0;
}