#include <bits/stdc++.h>

using namespace std;

int a[200005];

int L[200005], R[200005];

bool dfs(int l, int r, int x) {
	if (l > r || a[l] <= x && a[r] <= x) return false;
	if (a[l] <= x) return R[r] & 1;
	if (a[r] <= x) return L[l] & 1;
	if (!dfs(l + 1, r, a[l])) return true;
	if (!dfs(l, r - 1, a[r])) return true;
	return false;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) R[i] = a[i] < a[i - 1] ? R[i - 1] + 1 : 1;
	for (int i = n; i >= 1; --i) L[i] = a[i] < a[i + 1] ? L[i + 1] + 1 : 1;
	int ans = dfs(1, n, -1);
	printf("%s\n", ans ? "Alice" : "Bob");
	return 0;
}