#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
int main() {
	int n, q, r, c;
	scanf("%d %d", &n, &q);
	bool states[n + 1][2], block[n][2];
	set<int> blocked;
	memset(states, 0, sizeof states);
	memset(block, 0, sizeof block);
	for (int i = 0; i < q; ++i) {
		scanf("%d %d", &r, &c);
		if (block[c - 1][r - 1]) {
			if (c > 1) states[c - 1][r - 1] = block[c - 2][r - 1];
			else states[c - 2][r - 1] = false;
			if (c < n) states[c][r - 1] = block[c][r - 1];
			else states[c][r - 1] = false;
			if (!states[c - 1][r - 1]) blocked.erase(c - 1);
			if (!states[c][r - 1]) blocked.erase(c);
		} else {
			states[c - 1][r - 1] = states[c][r - 1] = true;
			if (states[c - 1][r - 1] && states[c - 1][2 - r]) blocked.insert(c - 1);
			if (states[c][r - 1] && states[c][2 - r]) blocked.insert(c);
		}
		block[c - 1][r - 1] = !block[c - 1][r - 1];
		printf(blocked.empty() ? "Yes\n" : "No\n");
	}
	return 0;
}