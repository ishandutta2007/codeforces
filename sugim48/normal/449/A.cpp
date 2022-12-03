#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

ll calc(ll n, ll m, ll k) {
	if (n + m - 2 < k)
		return -1;
	else if (n >= k + 1)
		return n / (k + 1) * m;
	else
		return m / (k - n + 2);
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	printf("%I64d\n", max(calc(n, m, k), calc(m, n, k)));
}