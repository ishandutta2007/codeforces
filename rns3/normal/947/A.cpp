#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

#define N 1010101

int a[N];

bool vis[N];
int p[N], cnt;

void prep() {
	for (int i = 1; i < N; i ++) a[i] = INF;
	for (int i = 2; i < N; i ++) if (!vis[i]) {
		p[++cnt] = i;
		for (int j = i * 2; j < N; j += i) {
			vis[j] = 1;
			a[j] = min(a[j], j - i + 1);
		}
	}
}

int main() {
	prep();
	int n;
	scanf("%d", &n);
	int ans = n;
	for (int i = n; i >= a[n]; i --) ans = min(ans, a[i]);
	printf("%d\n", ans);

	return 0;
}