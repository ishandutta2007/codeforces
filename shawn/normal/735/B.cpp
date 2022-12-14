#include <bits/stdc++.h>

using namespace std;

int read(){
	int x = 0, f = 1, c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void write(int x) {
	if (x < 0) puts("-"), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 1e5 + 10;

long long n, n1, n2, a[maxn], t1, s1, s2;

int main() {
	n = read(), n1 = read(), n2 = read();
	for (int i = 1; i <= n; i ++) a[i] = read();
	sort(a + 1, a + n + 1);
	if (n1 < n2) swap(n1, n2);
	for (int i = (n - n1 - n2) + 1; i <= n; i ++) {
		if (t1 < n1) {
			t1 ++;
			s1 += a[i];
		} 
		else {
			s2 += a[i];
		}
	}
	printf("%.8lf", ((double)s1 / (double)n1) + ((double)s2 / (double)n2));
	return 0;
}