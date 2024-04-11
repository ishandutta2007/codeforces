#include <bits/stdc++.h>

using namespace std;

long long read() {
	long long x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

const long long maxn = 2e5 + 10;

long long a[maxn], b[maxn], c[maxn], B[maxn], C[maxn], digit[40], ed;
long long n, sum;

bool check(long long i) {
	return B[i] == b[i] && C[i] == c[i];
}

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) {
		b[i] = read();
		sum += b[i];
	}
	for (int i = 1; i <= n; i ++) {
		c[i] = read();
		sum += c[i];
	}
	if (sum % (n << 1)) return puts("-1"), 0;
	sum /= (n << 1); // sum of array A
	for (int i = 1; i <= n; i ++) {
		a[i] = b[i] + c[i];
		a[i] -= sum;
		a[i] /= n;
		long long x = a[i], pos = 0;
		while (x) {
			digit[pos] += ((x % 2) == 1);
			pos ++;
			x /= 2;
			ed = max(ed, pos);
		}
	}

	for (int i = 1; i <= n; i ++) {
		//memset(dec, 0, sizeof dec);
		long long x = a[i], pos = 0;
		while (x || pos <= ed) {
			long long now = x % 2;
			if (now == 1) B[i] += digit[pos] * (1 << pos);
			pos ++;
			x /= 2;
		}
		x = a[i], pos = 0;
		while (x || pos <= ed) {
			long long now = x % 2;
			if (now == 1) C[i] += n * (1 << pos);
			else C[i] += digit[pos] * (1 << pos);
			pos ++;
			x /= 2;
		}
	}

	for (long long i = 1; i <= n; i ++) if (!check(i)) return puts("-1"), 0;
	for (long long i = 1; i <= n; i ++) printf("%d ", a[i]);

	return 0;
}