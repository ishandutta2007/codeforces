#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int t, n, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int cnt = 0, ok = 0;
		for (int i = 1; i <= n; i ++) if (a[i] % 2 == 0) cnt ++;
		for (int i = 1; i < n; i ++) if (a[i] + 1 == a[i+1]) ok = 1;
		if (cnt % 2 == 0) ok = 1;
		printf("%s\n", ok ? "YES" : "NO");
	}
}