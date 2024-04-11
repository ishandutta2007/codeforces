#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int getAns(int csa, int csb, int a, int b) {
	if (csa > csb) {
		swap(csa, csb);
		swap(a, b);
	}
	return max(0, min(a - csb, b - csb) + 1 - (csa == csb ? 1 : 0));
}

int main() {
	int n; scanf("%d", &n);
	int csa = 0, csb = 0;
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		ans += getAns(csa, csb, a, b);
		// printf("a %d\n", getAns(csa, csb, a, b));
		csa = a, csb = b;
	}
	printf("%lld\n", ans);
}