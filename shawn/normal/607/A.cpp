#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int N = 1e5 + 10;
pair <int, int> a[N];
int f[N], ans, n;

int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) a[i].X = rd(), a[i].Y = rd();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		pair <int, int> t;
		t.X = a[i].X - a[i].Y;
		int pos = lower_bound(a + 1, a + n + 1, t) - a;
		if (pos) f[i] = f[pos - 1] + (i - pos); else f[i] = i - 1;
	}
	int ans = n;
	for (int i = 1; i <= n; i ++) ans = min(ans, f[i] + (n - i));
	printf("%d\n", ans);
	return 0;
}