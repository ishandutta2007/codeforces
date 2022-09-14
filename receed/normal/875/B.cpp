#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, t, mx = 0;
	scanf("%d", &n);
	printf("%d ", 1);
	vector<int> used(n + 1, 0), c(n + 1);
	for (int i = 1; i <= n; i++)
		c[i] = i;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		used[t] = 1;
		while (used[c.back()])
			c.pop_back();
		printf("%d ", i - n + c.size() + 1);
	}
}