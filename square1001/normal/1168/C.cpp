#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
const int bits = 19;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	vector<int> X(Q), Y(Q);
	for (int i = 0; i < Q; ++i) cin >> X[i] >> Y[i], --X[i], --Y[i];
	vector<vector<int> > G(N);
	for (int i = 0; i < Q; ++i) {
		G[X[i]].push_back(i);
	}
	vector<vector<int> > cur(bits, vector<int>(bits, inf));
	vector<bool> ans(Q, false);
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < bits; ++j) {
			for (int k = 0; k < bits; ++k) {
				if (((A[i] >> j) & 1) && ((A[i] >> k) & 1)) cur[j][k] = i;
			}
		}
		for (int j = 0; j < bits; ++j) {
			int mn = inf;
			for (int k = 0; k < bits; ++k) {
				if ((A[i] >> k) & 1) {
					mn = min(mn, cur[k][j]);
				}
			}
			for (int k = 0; k < bits; ++k) {
				if ((A[i] >> k) & 1) {
					cur[k][j] = mn;
				}
			}
		}
		for (int j : G[i]) {
			for (int k = 0; k < bits; ++k) {
				for (int l = 0; l < bits; ++l) {
					if (((A[i] >> k) & 1) && ((A[Y[j]] >> l) & 1) && cur[k][l] <= Y[j]) {
						ans[j] = true;
					}
				}
			}
		}
	}
	for (int i = 0; i < Q; ++i) {
		cout << (ans[i] ? "Shi" : "Fou") << "\n";
	}
	return 0;
}