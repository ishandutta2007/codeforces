#include <cstdio>
#define Maxn 100002
#define Max(x, y) ((x) > (y) ? (x) : (y))

inline int read() {
	char c = getchar();
	int n = 0;
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return n;
}

int n, f[Maxn], ord[Maxn];
long long sum[Maxn], ans[Maxn];
bool ins[Maxn];

int find(int d) {
	return f[d] == d ? d : f[d] = find(f[d]);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		sum[i] = read();
		f[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		ord[i] = read();
	}
	ans[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		int t = ord[i];
		ins[t] = true;
		if (ins[t - 1]) {
			sum[t] += sum[find(t - 1)];
			f[find(t - 1)] = t;
		}
		if (ins[t + 1]) {
			sum[t] += sum[find(t + 1)];
			f[find(t + 1)] = t;
		}
		ans[i] = Max(ans[i + 1], sum[t]);
	}
	for (int i = 2; i <= n + 1; i++) {
		printf("%I64d\n", ans[i]);
	}
	return 0;
}

// By Sooke.
// CF722C Destroying Array.