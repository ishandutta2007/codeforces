#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n; scanf("%d", &n);
	int baseSize = 1;
	while (2 * baseSize + 1 <= n) baseSize = baseSize * 2 + 1;
	vector<int> color(baseSize + 1);
	for (int i = 2; i <= baseSize; ++i) color[i] = color[i >> 1] ^ (~i & 1);
	int k = 0;
	for (int i = 1; i <= baseSize / 2; ++i) {
		int nextLeaf = i * 2 + 1;
		while (2 * nextLeaf <= baseSize) nextLeaf = 2 * nextLeaf;
		if (color[nextLeaf] == color[i]) ++k;
	}
	if (n == k + baseSize || n == k + baseSize + 1) printf("1\n");
	else printf("0\n");
	return 0;
}