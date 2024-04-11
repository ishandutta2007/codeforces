#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i]; --A[i];
	}
	int ans = 0, pos = 0;
	while (pos < N) {
		int curmax = A[pos];
		while (pos < curmax) {
			++pos;
			curmax = max(curmax, A[pos]);
		}
		++pos;
		++ans;
	}
	cout << ans << endl;
	return 0;
}