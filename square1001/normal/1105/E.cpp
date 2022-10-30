#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maximum_independent_set(vector<vector<int> > G) {
	int N = G.size(), NL = N / 2, NR = N - NL;
	vector<int> lgbits(NL), lrgbits(NL), rgbits(NR);
	for (int i = 0; i < NL; ++i) {
		for (int j : G[i]) {
			if (j < NL) {
				lgbits[i] |= 1 << j;
			}
			else {
				lrgbits[i] |= 1 << (j - NL);
			}
		}
	}
	for (int i = 0; i < NR; ++i) {
		for (int j : G[i + NL]) {
			if (j >= NL) {
				rgbits[i] |= 1 << (j - NL);
			}
		}
	}
	vector<int> subans(1 << NR);
	for (int i = 1; i < 1 << NR; ++i) {
		int cnt = 0, bit = 0;
		for (int j = 0; j < NR; ++j) {
			if (!((i >> j) & 1)) continue;
			++cnt;
			bit |= rgbits[j];
		}
		if ((i & bit) == 0) subans[i] = cnt;
	}
	for (int i = 0; i < NR; ++i) {
		for (int j = 0; j < 1 << NR; ++j) {
			if ((j >> i) & 1) {
				subans[j] = max(subans[j], subans[j - (1 << i)]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 1 << NL; ++i) {
		int cnt = 0, bit = 0, bitr = 0;
		for (int j = 0; j < NL; ++j) {
			if (!((i >> j) & 1)) continue;
			++cnt;
			bit |= lgbits[j];
			bitr |= lrgbits[j];
		}
		if ((i & bit) == 0) {
			ans = max(ans, cnt + subans[(1 << NR) - bitr - 1]);
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<string> names;
	long long bit = 0;
	vector<vector<int> > G(M);
	for (int i = 0; i < N; ++i) {
		int tp;
		cin >> tp;
		if (tp == 1) bit = 0;
		else {
			string name;
			cin >> name;
			int ptr = find(names.begin(), names.end(), name) - names.begin();
			if (ptr == names.size()) names.push_back(name);
			for (int j = 0; j < M; ++j) {
				if (j != ptr && ((bit >> j) & 1)) {
					G[j].push_back(ptr);
					G[ptr].push_back(j);
				}
			}
			bit |= 1LL << ptr;
		}
	}
	int ans = maximum_independent_set(G);
	cout << ans << endl;
	return 0;
}