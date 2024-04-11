#include <bits/stdc++.h>
using namespace std;

#define N 1020

int n, a[N], t;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	t = 1;
	for (int i = 1; i < n; i ++) {
		if (a[i] < a[i + 1]) t = i + 1;
		else break;
	}
	while (a[t] == a[t + 1] && t < n) t ++;
	for (int i = t; i < n; i ++) {
		if (a[i] <= a[i + 1]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}