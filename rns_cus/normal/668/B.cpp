#include <bits/stdc++.h>
using namespace std;

#define gc getchar
#define pc putchar

int getint() {
	unsigned int c;
	int x = 0;
	while (((c = gc()) - '0') >= 10) {
		if (c == '-') return -getint();
		if (!~c) exit(0);
	}
	do {
		x = (x << 3) + (x << 1) + (c - '0');
	} while (((c = gc()) - '0') < 10);
	return x;
}

void putint(int n) {
	int i = 32, a[i];
	if (n < 0) pc('-');
	do {
		a[-- i] = 48 + abs(n % 10);
		n /= 10;
	} while (n);
	while (i < 32) pc(a[i ++]);
}

#define N 1000100

int n, q, a, b[N];

int calc(int m) {
	return (m + n - 1) % n + 1;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &q);
	int sum = 0, k = 0;
	while (q --) {
		a = getint();
		if (a == 1) a = getint(), sum = (sum + a + n) % n;
        else {
			if ((sum + k) & 1) k --;
			else k ++;
			k = (k + n) % n;
        }
	}
	for (int i = 1; i <= n; i ++) {
		if (i & 1) b[calc(i+sum+k)] = i;
		else b[calc(i+sum-k)] = i;
	}
	for (int i = 1; i <= n; i ++) {
		putint(b[i]);
		if (i < n) printf(" ");
		else puts("");
	}
	return 0;
}