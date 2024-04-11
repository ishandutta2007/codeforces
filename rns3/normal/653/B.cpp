#include <bits/stdc++.h>
using namespace std;
#define M 50
int a[M], b[M], n, q, ans, c[M];
char s[M], ss[M];

bool check(int x) {
	for (int i = 0; i < n; i++) c[i] = x % 10, x /= 10;
	int cur = 0;
	while (cur < n - 1) {
		int bf = 0;
		for (int i = 0; i < q; i++) {
			if (a[i] == 10 * c[cur] + c[cur+1]) {
				bf = 1; c[++cur] = b[i]; break;
			}
		}
		if (!bf) return 0;
	}

	if (c[cur] == 0) return 1;
	else return 0;
}

void dfs(int x, int dp) {
	if (dp == n) {
		if (check(x)) ans++;
		return;
	}
	for (int i = 0; i < 6; i++) {
		dfs(10 * x + i, dp + 1);
	}
}

int main() {
//freopen("B.in", "r", stdin);
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%s %s", s, ss);
		a[i] = (s[0]-'a') * 10 + s[1] - 'a';
		b[i] = ss[0] - 'a';
	}
	dfs(0, 0);
	printf("%d\n", ans);
}