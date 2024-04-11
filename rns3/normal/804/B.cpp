#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define N 1010101

char s[N];

int a[N];

int main() {
	//freopen("r.in", "r", stdin);
	int n;
	gets(s);
	n = strlen(s);
	int e = 0, now = 0;
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'a') a[++e] = now, now = 0;
		else now ++;
	}
	a[++e] = now;
	int ans = 0;
	for (int i = 2, t = 1; i <= e; i ++) {
		ans = (ans + 1ll * a[i] * t) % mod;
		t = (t * 2 + 1) % mod;
	}
	printf("%d\n", ans);

	return 0;
}