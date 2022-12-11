#include <bits/stdc++.h>

using namespace std;

void addNumberTo(int v, int offset, int mult, vector<int> &ans) {
	for (int b = 0; b + offset < ans.size(); ++b) {
		if (v & (1 << b)) ans[b + offset] += mult;
	}
}

void massPopCount(int l, int r, int offset, int mult, vector<int> &ans) {
	if (l % 2 == 1) addNumberTo(l++, offset, mult, ans);
	if (l > r) return;
	if (r % 2 == 0) addNumberTo(r--, offset, mult, ans);
	if (l > r) return;
	ans[offset] += ((r - l + 1) / 2) * mult;
	massPopCount(l/2, r/2, offset+1, 2 * mult, ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int l, r; scanf("%d %d", &l, &r);
		vector<int> mpc(30);
		massPopCount(l, r, 0, 1, mpc);
		int ans = r - l + 1;
		for (int v : mpc) {
			ans = min(ans, (r - l + 1) - v);
		}
		printf("%d\n", ans);
	}
}