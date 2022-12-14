#include <bits/stdc++.h>
using namespace std;

long long x;

#define N 101010

char s[N];

int calc(long long x) {
	int rlt = 0;
	while (x) {
		rlt += x % 10;
		x /= 10;
	}
	return rlt;
}

int main() {
	gets(s);
	int n = strlen(s);
	if (n == 1) {
		printf("%d\n", (int)(s[0] - '0'));
		return 0;
	}
	long long a = s[0] - '0';
	for (int i = 1; i < n; i ++) a *= 10;
	long long b = 0;
	for (int i = 1; i < n; i ++) b = b * 10 + (s[i] - '0');
	b ++, a --;
	int ans = calc(a) + calc(b);
	printf("%d\n", ans);

	return 0;
}