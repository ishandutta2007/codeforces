#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, a[100009], b[100009], ra[100009], rb[100009]; long long s[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) s[i + 1] = b[i] = abs(a[i] - a[i + 1]) * (i & 1 ? -1 : 1);
	for (int i = 1; i < n; i++) s[i] += s[i - 1];
	ra[n - 1] = n - 1, rb[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		ra[i] = s[ra[i + 1]] < s[i] ? i : ra[i + 1];
		rb[i] = s[rb[i + 1]] > s[i] ? i : rb[i + 1];
	}
	long long ret = -1LL << 60;
	for (int l = 0; l < n - 1; l++) {
		if (l & 1) ret = max(ret, s[l] - s[rb[l + 1]]);
		else ret = max(ret, s[ra[l + 1]] - s[l]);
	}
	printf("%lld\n", ret);
	return 0;
}