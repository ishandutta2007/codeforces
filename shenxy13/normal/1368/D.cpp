#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[n], bitcount[20];
	fill_n(bitcount, 20, 0);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (a[i] & (1 << j)) ++bitcount[j];
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		long long rec = 0;
		for (int j = 0; j < 20; ++j) {
			if (bitcount[j]) rec += (1 << j), --bitcount[j];
		}
		ans += rec * rec;
	}
	printf("%lld", ans);
	return 0;
}