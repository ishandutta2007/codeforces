#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> p(n);
	for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
	for (int i = 0; i < n; ++i) --p[i];
	vector<bool> vis(n);
	int cycleCount = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			++cycleCount;
			for (int ci = i; !vis[ci]; ci = p[ci]) vis[ci] = true;
		}
	}
	vector<int> toFlip(n);
	for (int i = 0; i < n; ++i) scanf("%d", &toFlip[i]);
	int totalFlip = 0;
	for (int x : toFlip) totalFlip ^= x;
	printf("%d\n", (cycleCount == 1 ? 0 : cycleCount) + (1 - totalFlip));
	return 0;
}