#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, x, a, c[1029], d[1029];
int main() {
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < n; i++) scanf("%d", &a), c[a]++;
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j <= 1024; j++) {
			int p = ((sum + c[j]) >> 1) - (sum >> 1);
			d[j] += p;
			d[j ^ x] += c[j] - p;
			sum += c[j];
		}
		for (int j = 0; j <= 1024; j++) c[j] = d[j], d[j] = 0;
	}
	int l = 999999999, r = -1;
	for (int i = 0; i <= 1024; i++) {
		if (c[i]) {
			l = min(l, i);
			r = max(r, i);
		}
	}
	printf("%d %d\n", r, l);
	return 0;
}