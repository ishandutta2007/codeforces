#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		ll total = 0;
		for (int i = 0; i < n; ++i) {
			ll ai; scanf("%lld", &ai);
			total += ai;
		}
		printf("%d\n", total % n == 0 ? 0 : 1);
	}
}