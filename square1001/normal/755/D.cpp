#include <cstdio>
#pragma warning(disable : 4996)
int n, m, bit[2000009];
void add(int i, int x) {
	i++;
	while (i <= 2 * n) {
		bit[i] += x;
		i += i & (-i);
	}
}
long long sum(int r) {
	long long ret = 0;
	while (r >= 1) {
		ret += bit[r];
		r -= r & (-r);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	if (m * 2 > n) m = n - m;
	int pos = 0; long long ret = 1;
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		ret += sum(pos + m) - sum(pos + 1) + 1;
		int z = pos + m;
		if (z >= n) z -= n;
		add(pos, 1); add(pos + n, 1);
		add(z, 1); add(z + n, 1);
		printf("%lld", ret);
		pos = z;
	}
	printf("\n");
	return 0;
}