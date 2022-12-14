#include <bits/stdc++.h>

using namespace std;

long long read(){
	long long x = 0, f = 1, c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void write(long long x) {
	if (x < 0) puts("-"), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

long long lcm(long long a, long long b) {
	return a / __gcd(a, b) * b ;
}

long long n, k;

int main() {
	n = read(), k = read();
	long long a = 1;
	for (long long i = 1; i <= n; i ++) {
		a = lcm(a, read()) % k;
		if (a % k == 0) return puts("Yes"), 0;
	}
	puts("No");
	return 0;
}