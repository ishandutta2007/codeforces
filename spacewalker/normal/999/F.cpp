#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	map<int, int> cards;
	for (int i = 0; i < n * k; ++i) {
		int x; scanf("%d", &x);
		++cards[x];
	}
	map<int, int> faves;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x); ++faves[x];
	}
	vector<int> rewards(k + 1);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &rewards[i + 1]);
	}
	int ans = 0;
	for (auto n_c : faves) {
		int pc = n_c.second, cc = cards[n_c.first];
//		printf("solving %d %d\n", pc, cc);
		vector<vector<int>> opt(pc + 1, vector<int>(cc + 1, 0));
		for (int i = 1; i <= pc; ++i) {
			for (int cards = 0; cards <= cc; ++cards) {
				for (int cpc = 0; cpc <= min(k, cards); ++cpc) {
					opt[i][cards] = max(opt[i][cards], rewards[cpc] + opt[i-1][cards-cpc]);
				}
//				printf("opt[%d][%d] = %d\n", i, cards, opt[i][cards]);
			}
		}
		ans += opt[pc][cc];
	}
	printf("%d\n", ans);
	return 0;
}