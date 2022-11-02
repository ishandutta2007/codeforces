#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, k, a[N], vis[N*N];

int get() {
	for (int i = 1; i <= n * k; i ++) {
		if (!vis[i]) {vis[i] = 1; return i;}
	}
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i ++) scanf("%d", &a[i]), vis[a[i]] = 1;
	for (int i = 1; i <= k; i ++) {
		printf("%d", a[i]);
		for (int j = 1; j < n; j ++) printf(" %d", get());
		puts("");
	}
	return 0;
}