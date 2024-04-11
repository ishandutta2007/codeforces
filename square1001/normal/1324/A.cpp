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
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		bool ok = true;
		for (int i = 0; i < N; ++i) {
			if (A[i] % 2 != A[0] % 2) {
				ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}