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
		int N, K;
		cin >> N >> K;
		vector<vector<int> > A(N, vector<int>(N));
		cout << (K % N == 0 ? 0 : 2) << '\n';
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (K > 0) {
					A[j][(i + j) % N] = 1;
					--K;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << A[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}