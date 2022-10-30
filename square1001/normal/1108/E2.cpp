#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	vector<int> L(M), R(M), C = { 0, N };
	for (int i = 0; i < M; ++i) {
		cin >> L[i] >> R[i]; --L[i];
		C.push_back(L[i]);
		C.push_back(R[i]);
	}
	sort(C.begin(), C.end());
	C.erase(unique(C.begin(), C.end()), C.end());
	int S = C.size();
	vector<int> mx(S - 1, -inf), mn(S - 1, inf);
	for (int i = 0; i < S - 1; ++i) {
		for (int j = C[i]; j < C[i + 1]; ++j) {
			mx[i] = max(mx[i], A[j]);
			mn[i] = min(mn[i], A[j]);
		}
	}
	int ans = 0;
	vector<int> ansv;
	for (int i = 0; i < S - 1; ++i) {
		for (int j = 0; j < S - 1; ++j) {
			if (i == j && C[i + 1] - C[i] == 1) continue;
			int delta = mx[i] - mn[j];
			vector<int> st;
			for (int k = 0; k < M; ++k) {
				if (!(L[k] <= C[i] && C[i] < R[k]) && (L[k] <= C[j] && C[j] < R[k])) {
					++delta;
					st.push_back(k);
				}
			}
			if (ans < delta) {
				ans = delta;
				ansv = st;
			}
		}
	}
	cout << ans << endl;
	cout << ansv.size() << endl;
	for (int i = 0; i < ansv.size(); ++i) {
		if (i) cout << ' ';
		cout << ansv[i] + 1;
	}
	cout << endl;
	return 0;
}