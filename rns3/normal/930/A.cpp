#include <bits/stdc++.h>
using namespace std;

#define N 101010

int d[N];

int cnt[N];

int n;

int main() {
	scanf("%d", &n);
	d[1] = 1;
	cnt[1] = 1;
	int p;
	for (int i = 2; i <= n; i ++) scanf("%d", &p), d[i] = d[p] + 1, cnt[d[i]] ++;
	int ans = 0;
	for (int i = 1; i <= n; i ++) if (cnt[i] & 1) ans ++;
	printf("%d\n", ans);

	return 0;
}