#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> L(N, -inf), R(N, inf);
	for (int i = 0; i < Q; ++i) {
		int x;
		cin >> x; --x;
		L[x] = max(L[x], i);
		R[x] = min(R[x], i);
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = -1; j <= 1; ++j) {
			int p = i + j;
			if (0 <= p && p < N && L[i] < R[p]) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}