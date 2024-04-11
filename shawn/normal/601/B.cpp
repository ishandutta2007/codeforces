#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int N = 1e5 + 10;

int n, q, a[N], b[N], s[N], top, L[N], R[N], l, r, len;

int main() {
	n = rd(), q = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	while (q--) {
		int l = rd(), r = rd(), len = r - l + 1;
		for (int i = l; i < r; i ++) b[i - l + 1] = abs(a[i] - a[i + 1]);
		top = 0;
		for (int i = 1; i < len; i ++) {
			while (top && b[i] >= b[s[top]]) top--;
			L[i] = s[top], s[++top] = i;
		}
		top = 0;
		for (int i = len - 1; i; i --) {
			while (top && b[i] > b[s[top]]) top--;
			R[i] = top == 0 ? len : s[top], s[++top] = i;
		}
		long long ans = 0;
		for (int i = 1; i < len; i ++) ans += 1ll * (i - L[i]) * (R[i] - i) * b[i];//, printf("%d %d %d\n", i, L[i], R[i]);;
		printf("%I64d\n", ans);
	}
	return 0;
}