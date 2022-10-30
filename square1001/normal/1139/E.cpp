#include <vector>
#include <iostream>
#include <functional>
using namespace std;
const int limit = 5001;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i]; --C[i];
	}
	int D;
	cin >> D;
	vector<int> K(D);
	vector<bool> used(N, true);
	for (int i = 0; i < D; ++i) {
		cin >> K[i]; --K[i];
		used[K[i]] = false;
	}
	vector<vector<int> > G(M + limit);
	vector<int> match(M + limit, -1);
	vector<bool> vis;
	function<bool(int)> find_augment = [&](int pos) {
		vis[pos] = true;
		for (int i : G[pos]) {
			if (match[i] == -1 || (!vis[match[i]] && find_augment(match[i]))) {
				match[pos] = i;
				match[i] = pos;
				return true;
			}
		}
		return false;
	};
	int mex = 0;
	while (true) {
		for (int i = 0; i < N; ++i) {
			if (P[i] == mex && used[i]) {
				G[C[i]].push_back(mex + M);
				G[mex + M].push_back(C[i]);
			}
		}
		vis = vector<bool>(M + limit, false);
		bool res = find_augment(mex + M);
		if (!res) break;
		++mex;
	}
	vector<int> ans(D);
	for (int i = D - 1; i >= 0; --i) {
		ans[i] = mex;
		used[K[i]] = true;
		if (P[K[i]] <= mex) {
			G[C[K[i]]].push_back(P[K[i]] + M);
			G[P[K[i]] + M].push_back(C[K[i]]);
			while (true) {
				vis = vector<bool>(M + limit, false);
				bool res = find_augment(mex + M);
				if (!res) break;
				++mex;
				for (int j = 0; j < N; ++j) {
					if (P[j] == mex && used[j]) {
						G[C[j]].push_back(mex + M);
						G[mex + M].push_back(C[j]);
					}
				}
			}
		}
	}
	for (int i = 0; i < D; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}