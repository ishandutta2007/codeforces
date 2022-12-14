#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar(); 
	return x;
}

int a[500005], ans[500005], n, len;
int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	int i = 1, j = 1;
	for (; i <= n; i ++) {
		for (j = i; j < n; j ++) if (a[j + 1] == a[j]) break;
		for (int k = i; k <= j; k ++) if (k - i < j - k) ans[k] = a[i]; else ans[k] = a[j];
		len = max(len, j - i - 1);
		i = j;
	}
	len = max(len, j - i - 1);
	printf("%d\n", (len + 1) / 2);
	for (int i = 1; i <= n; i ++) putchar(ans[i] + 48), putchar(32); puts("");
	return 0;
}