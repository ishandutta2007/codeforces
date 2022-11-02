#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<vector<int> > g(N);
	int limit = 0;
	for (int i = 0; i < N; ++i) {
		int x, rad = 1;
		cin >> x;
		for (int j = 2; j * j <= x; ++j) {
			int cnt = 0;
			while (x % j == 0) x /= j, cnt ^= 1;
			if (cnt == 1) g[i].push_back(j), rad *= j;
		}
		if (x > 1) g[i].push_back(x), rad *= x;
		limit = max(limit, rad);
	}
	vector<vector<pair<int, int> > > qs(N + 1);
	for (int i = 0; i < Q; ++i) {
		int L, R;
		cin >> L >> R; --L;
		qs[R].push_back(make_pair(L, i));
	}
	vector<vector<int> > curopt(limit + 1, vector<int>(8, -inf));
	vector<int> curbound(15, -inf);
	vector<int> ans(Q);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 1 << g[i].size(); ++j) {
			int rem = 0, mul = 1;
			for (int k = 0; k < g[i].size(); ++k) {
				if ((j >> k) & 1) mul *= g[i][k];
				else ++rem;
			}
			for (int k = 0; k <= 7; ++k) {
				curbound[rem + k] = max(curbound[rem + k], curopt[mul][k]);
			}
			curopt[mul][rem] = i;
		}
		for (pair<int, int> j : qs[i + 1]) {
			for (int k = 0; k <= 14; ++k) {
				if (curbound[k] >= j.first) {
					ans[j.second] = k;
					break;
				}
			}
		}
	}
	for (int i = 0; i < Q; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}