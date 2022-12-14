#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int p[n];
	for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
	int ptr = -1;
	long long sum = 0, cnt = 1;
	for (int i = 0; i < n; ++i) {
		if (p[i] > n - k) {
			sum += p[i];
			if (ptr != -1) cnt *= i - ptr, cnt %= 998244353;
			ptr = i;
		}
	}
	printf("%lld %lld", sum, cnt);
	return 0;
}