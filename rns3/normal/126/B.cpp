#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, h[N], k, mx, ans;
char s[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 2; i <= n; i ++) {
		while (k && s[k + 1] != s[i]) k = h[k];
		if (s[k + 1] == s[i]) k ++;
		h[i] = k;
	}
	for (int i = 2; i < n; i ++) mx = max(mx, h[i]);
	ans = h[n];
	while (ans) {
		if (ans <= mx) break;
		else ans = h[ans];
	}
	if (!ans) puts("Just a legend");
	else for (int i = 1; i <= ans; i ++) printf("%c", s[i]);
}