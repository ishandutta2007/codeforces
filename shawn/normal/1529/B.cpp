#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1e5 + 10;

int a[N], b[N];

void solve() {
	int n = rd(), mn = 1e9, ans = 0;
	for (int i = 1; i <= n; i ++) {
		a[i] = rd();
		if (a[i] <= 0) b[++ans] = a[i];
	}
	sort(b + 1, b + ans + 1);
	for (int i = 1; i < ans; i ++) 	mn = min(mn, abs(b[i] - b[i + 1]));
	for (int i = 1; i <= n; i ++) {
		if (a[i] > 0 && a[i] <= mn) {ans ++; break;}
	} 
	printf("%d\n", ans);
}

int main() {
	for (int t = rd(); t; t--) solve();
	return 0;
}