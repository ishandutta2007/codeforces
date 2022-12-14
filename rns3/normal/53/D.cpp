#include <bits/stdc++.h>
using namespace std;

#define N 310

int n, a[N], b[N], vis[N], ab[N], ba[N], e = 0;

pair <int, int> ans[1100000];

void display(int k, int i) {
	for (int j = k - 1; j >= i; j --) ans[++e] = make_pair(j, j + 1);
}

int main() {
	scanf("%d", &n);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && b[j] == a[i]) {
				ab[i] = j;
				ba[j] = i;
				vis[j] = 1;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
        display(ab[i], i);
        for (int j = ab[i] - 1; j >= i; j --) {
			ab[ba[j]] = j + 1;
			ba[j+1] = ba[j];
        }
	}
	printf("%d\n", e);
	for (int i = 1; i <= e; i ++) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}