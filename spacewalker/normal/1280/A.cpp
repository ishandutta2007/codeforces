#include <bits/stdc++.h>


using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

char cString[600];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int x; scanf("%d", &x);
		scanf("%s", cString);
		vector<int> vim;
		for (int i = 0; cString[i]; ++i) vim.push_back(cString[i] - '0');
		ll cLength = vim.size();
		for (int i = 0; i < x; ++i) {
			if (vim.size() < x) {
				// add these
				int addFrom = i + 1;
				int addTo = vim.size();
				for (int rep = 0; rep < vim[i] - 1; ++rep) {
					for (int i = addFrom; i < addTo; ++i) {
						vim.push_back(vim[i]);
					}
				}
				cLength = vim.size();
			} else {
				ll addedLength = (cLength - i - 1 + MOD) * (vim[i] - 1) % MOD;
//				printf("%lld added\n", addedLength);
				cLength = (cLength + addedLength) % MOD;
			}
//			printf("stage %d, length %lld:\n", i, cLength);
//			for (int x : vim) printf("%d", x);
//			printf("\n");
		}
		printf("%lld\n", cLength);
	}
}