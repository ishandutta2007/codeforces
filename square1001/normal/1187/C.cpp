#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> S(N - 1), T(Q), L(Q), R(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> T[i] >> L[i] >> R[i]; --L[i];
	}
	for (int i = 0; i < Q; ++i) {
		if (T[i] == 1) {
			for (int j = L[i]; j < R[i] - 1; ++j) {
				S[j] = 1;
			}
		}
	}
	bool valid = true;
	for (int i = 0; i < Q; ++i) {
		if (T[i] == 0) {
			bool ok = false;
			if (R[i] - L[i] <= 1) ok = true;
			for (int j = L[i]; j < R[i] - 1; ++j) {
				if (S[j] == 0) ok = true;
			}
			if (!ok) valid = false;
		}
	}
	if (!valid) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		vector<int> arr(N);
		int cur = 100000000;
		arr[0] = cur;
		for (int i = 0; i < N - 1; ++i) {
			if (S[i] == 1) arr[i + 1] = arr[i] + 1;
			else arr[i + 1] = arr[i] - 2000;
		}
		for (int i = 0; i < N; ++i) {
			if (i) cout << ' ';
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}