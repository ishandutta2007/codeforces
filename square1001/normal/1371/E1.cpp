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
	int N, P;
	cin >> N >> P;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int mx = *max_element(A.begin(), A.end());
	vector<int> sum(mx + N + 1);
	for (int i = 0; i < N; ++i) {
		++sum[A[i]];
	}
	for (int i = 0; i < mx + N; ++i) {
		sum[i + 1] += sum[i];
	}
	vector<int> ans;
	for (int i = 0; i < mx; ++i) {
		bool ok = true;
		for (int j = 0; j < N; ++j) {
			if (sum[i + j] <= j || (sum[i + j] - j) % P == 0) {
				ok = false;
				break;
			}
		}
		if (ok) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		if (i) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
	return 0;
}