#include <bits/stdc++.h>
using namespace std;
#define N 500500

int a[N];
char s[N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) {
		a[i] = (s[i] - '0');
		a[i] %= 4;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (!a[i]) ans ++;
	}
	for (int i = 2; i <= n; i ++) {
		if ((a[i-1] * 10 + a[i]) % 4 == 0) ans += i - 1;
	}
	printf("%I64d\n", ans);
	return 0;
}