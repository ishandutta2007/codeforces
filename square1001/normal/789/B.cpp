#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int b, q, l, m, a[100009];
int main() {
	scanf("%d %d %d %d", &b, &q, &l, &m);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	sort(a, a + m);
	int ret = 0; long long w = b;
	for (int i = 0; i < 123456 && abs(w) <= l; i++) {
		if (!binary_search(a, a + m, w)) ret++;
		w *= q;
	}
	if (ret >= 10000) puts("inf");
	else printf("%d\n", ret);
	return 0;
}