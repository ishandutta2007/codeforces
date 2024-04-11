#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int pre = 0, ans = 0;
		for (int i = 0; i < N; ++i) {
			if (A[i] <= i - pre + 1) {
				pre = i + 1;
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}