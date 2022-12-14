#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

#define N 200010

long long a[N], b[N];
char s[N];

long long expmod(long long n, int k) {
	if (!k) return 0;
	if (k == 1) return n;
	long long rlt = expmod(n, k / 2);
	rlt = rlt * rlt % P;
	if (k % 2) rlt = rlt * n % P;
	return rlt;
}

void prep() {
	a[0] = 1;
	b[0] = 1;
	for (int n = 1; n < N; n ++) {
		a[n] = a[n-1] * n % P;
		b[n] = expmod(a[n], P - 2);
	}
}

int main() {
	prep();
	gets(s);
	int n = strlen(s), m = 0, x = -1, y;
	for (int i = 0; i < n; i ++) if (s[i] == '(') m ++;
	y = n - m;
	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		if (s[i] == '(') {
			x ++;
			ans = (ans + ((a[x+y] * b[x+1] % P) * b[y-1]) % P) % P;
		}
		else y --;
	}
	printf("%I64d\n", ans);
	return 0;
}