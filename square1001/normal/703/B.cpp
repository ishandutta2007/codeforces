#include <string>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, c[100009], p[100009]; bool f[100009];
int main() {
	scanf("%d %d", &n, &m);
	long long ret = 0; int sum = 0, esum = 0;
	for (int i = 0; i < n; i++) scanf("%d", &c[i]), esum += c[i];
	for (int i = 0; i < m; i++) {
		scanf("%d", &p[i]); f[--p[i]] = true;
		ret -= c[p[i]] * c[p[i]];
		sum += c[p[i]];
	}
	esum -= sum;
	ret += 1LL * sum * sum; ret /= 2;
	for (int i = 0; i < m; i++) ret += 1LL * c[p[i]] * esum;
	for (int i = 0; i < n; i++) {
		if (!f[i] && !f[(i + 1) % n]) ret += c[i] * c[(i + 1) % n];
	}
	printf("%lld\n", ret);
	return 0;
}