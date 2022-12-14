#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	long long n, m;
	scanf("%I64d %I64d", &n, &m);
	long long k = min(n, m + (long long)(sqrt(max(1ll * 0, 8 * (n - m - 1) + 1)) - 1) / 2 + 1);
	printf("%I64d\n", k);
	return 0;
}