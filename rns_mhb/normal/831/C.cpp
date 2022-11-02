#include <bits/stdc++.h>
using namespace std;

#define N 2010
#define M 4000100

int n, k, a[N], b[N], d, num;
set <int> S;
bool vis[M << 1];

bool test(int x) {
	S.clear();
	for (int i = 1; i <= n; i ++) {
		x += a[i];
		S.insert(x);
	}
	for (int i = 1; i <= k; i ++) if (S.find(b[i]) == S.end()) return 0;
	return 1;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= k; i ++) scanf("%d", &b[i]);
	d = b[k];
	for (int i = 1; i <= n; i ++) {
		d -= a[i];
		if (test(d)) {
			if (!vis[d + M]) num ++;
			vis[d + M] = 1;
		}
	}
	printf("%d", num);
}