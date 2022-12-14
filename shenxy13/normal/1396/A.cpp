#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	long long A[n];
	for (int i = 0; i < n; ++i) scanf("%lld", &A[i]);
	printf("1 1\n");
	printf("%lld\n", -A[0]);
	A[0] = 0;
	if (n != 1) {
		printf("2 %d\n", n);
		printf("%lld", (A[1] % n) * (n - 1));
		for (int i = 2; i < n; ++i) printf(" %lld", (A[i] % n) * (n - 1));
		for (int i = 1; i < n; ++i) A[i] += (A[i] % n) * (n - 1);
		printf("\n");
	} else printf("1 1\n0\n");
	printf("1 %d\n", n);
	for (int i = 0; i < n; ++i) printf("%lld ", -A[i]);
	return 0;
}