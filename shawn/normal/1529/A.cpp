#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

int a[110]; 
void solve() {
	int n = rd();
	int ans = 0;
	for (int i = 1; i <= n; i ++) a[i] = rd();
	sort(a + 1, a + n + 1);
	for (int i = n; i; i --) {
		double avg = (1.0 * a[i] + a[1]) / 2;
		if (1.0 * a[i] > avg) ans ++;
		else break;
	}
	printf("%d\n", ans);
}

int main() {
	for (int t = rd(); t; t--) 
		solve();
	return 0;
}