#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, k, d[N], dd[N];
char s[N];

char calc(char c, int d) {
	if (c >= 'a' + d) return c - d;
	else return c + d;
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d %s", &n, &k, &s);
	int sum = 0;
	for (int i = 0; i < n; i ++) {
		d[i] = max(s[i] - 'a', 'z' - s[i]);
		sum += d[i];
	}
	if (sum < k) {
		puts("-1"); return 0;
	}
	for (int i = 0; i < n; i ++) {
		dd[i] = min(k, d[i]), k -= dd[i];
	}
	for (int i = 0; i < n; i ++) putchar(calc(s[i], dd[i]));
	puts("");
	return 0;
}