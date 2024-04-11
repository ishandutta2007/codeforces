#include <bits/stdc++.h>
using namespace std;

#define N 303030

int n;
bool vis[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	printf("1");
	int cur = n;
	for (int i = 1, x; i <= n; i ++) {
		scanf("%d", &x);
		vis[x] = 1;
		while (vis[cur]) cur --;
		printf(" %d", i - (n - 1 - cur));
	}

	return 0;
}