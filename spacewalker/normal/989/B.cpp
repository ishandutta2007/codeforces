#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char str[5000];

int main() {
	int n, p; scanf("%d %d", &n, &p);
	scanf("%s", str);
	vector<vector<char>> bySlot(p, vector<char>());
	for (int i = 0; i < n; ++i) {
		bySlot[i%p].push_back(str[i]);
	}
	vector<char> zct(p), oct(p), pct(p);
	for (int slot = 0; slot < p; ++slot) {
		for (char c : bySlot[slot]) {
			if (c == '0') ++zct[slot];
			if (c == '1') ++oct[slot];
			if (c == '.') ++pct[slot];
		}
		int startFill = (zct[slot] > 0 ? 1 : 0);
		for (int i = 0; i < bySlot[slot].size(); ++i) {
			if (bySlot[slot][i] == '.') {
				bySlot[slot][i] = startFill + '0';
				startFill = startFill ^ 1;
			}
		}
	}
	vector<char> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i] = bySlot[i%p][i/p];
	}
	bool isPeriod = true;
	for (int i = 0; i < n - p; ++i) {
		// printf("check pair %d %d\n", i, i+p);
		if (ans[i] != ans[i+p]) isPeriod = false;
	}
	if (isPeriod) printf("No\n");
	else {
		for (char c : ans) printf("%c", c);
		printf("\n");
	}
	return 0;
}