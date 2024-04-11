#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
const int mod = 1000000007;
int n, a[300009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int ret = 0, sum = 0, mul = 1;
	for (int i = 0; i < n; i++) {
		ret = (ret + 1LL * (mul - 1) * a[i] - sum + mod) % mod;
		mul *= 2; if (mul >= mod) mul -= mod;
		sum = (2LL * sum + a[i]) % mod;
	}
	printf("%d\n", ret);
	return 0;
}