#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q; string S;
	cin >> N >> S >> Q;
	vector<vector<int> > C(N + 1, vector<int>(26));
	for (int i = 0; i < N; ++i) {
		C[i + 1] = C[i];
		++C[i + 1][S[i] - 'a'];
	}
	for (int i = 0; i < Q; ++i) {
		string T;
		cin >> T;
		vector<int> X(26);
		for (int j = 0; j < T.size(); ++j) {
			++X[T[j] - 'a'];
		}
		int L = 0, R = N + 1;
		while (R - L > 1) {
			int M = (L + R) >> 1;
			bool ok = true;
			for (int j = 0; j < 26; ++j) {
				if (C[M][j] < X[j]) {
					ok = false; break;
				}
			}
			if (ok) R = M;
			else L = M;
		}
		cout << R << '\n';
	}
	return 0;
}