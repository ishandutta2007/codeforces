#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	ll n, m, k;
	scanf("%I64d %I64d %I64d ", &n, &m, &k);
	ll lb = 0, ub = n * m;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2, K = 0;
		for (int i = 1; i <= n; i++)
			K += min(m, mid / i);
		if (K < k)
			lb = mid;
		else
			ub = mid;
	}
	printf("%I64d \n", ub);
}