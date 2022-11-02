#include <cstdio>
#include <algorithm>
using namespace std;
int n, x, cnt[100009], res[100009]; bool prime[100009];
int main() {
	fill(prime + 2, prime + 100001, true);
	for (int i = 2; i * i <= 100000; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= 100000; j += i) prime[j] = false;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x), cnt[x]++;
	for (int i = 1; i <= 100000; i++) {
		if (!prime[i]) continue;
		for (int j = i; j <= 100000; j += i) res[i] += cnt[j];
	}
	res[0] = 1;
	printf("%d\n", *max_element(res, res + 100001));
	return 0;
}