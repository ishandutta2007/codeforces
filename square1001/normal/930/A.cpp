#include <cstdio>
#pragma warning(disable : 4996)
int n, p, d[100009], c[100009];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) scanf("%d", &p), d[i] = d[--p] + 1;
	for (int i = 0; i < n; i++) c[d[i]]++;
	int ret = 0;
	for (int i = 0; i < n; i++) ret += c[i] % 2;
	printf("%d\n", ret);
	return 0;
}