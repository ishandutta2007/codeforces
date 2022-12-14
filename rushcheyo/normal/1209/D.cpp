#include <bits/stdc++.h>
using namespace std;

int n, k, fa[100005];

int find(int x) {
	return !fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	scanf("%d%d", &n, &k);
	int ans = k;
	for (int i = 1, x, y; i <= k; ++i) {
		scanf("%d%d", &x, &y);
		x = find(x), y = find(y);
		if (x != y) --ans, fa[x] = y;
	}
	printf("%d\n", ans);
}