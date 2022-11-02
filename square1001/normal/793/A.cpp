#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[100009];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	bool f = true;
	for (int i = 1; i < n; i++) {
		if (a[i] % m != a[i - 1] % m) f = false;
	}
	if (!f) printf("-1\n");
	else {
		int r = *min_element(a, a + n); long long ret = 0;
		for (int i = 0; i < n; i++) ret += (a[i] - r) / m;
		printf("%lld\n", ret);
	}
	return 0;
}