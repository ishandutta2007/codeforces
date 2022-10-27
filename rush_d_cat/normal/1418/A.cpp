#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
LL x, y, k;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%lld%lld", &x ,&y, &k);
		LL need = k + k * y;
		LL c1 = (need - 1 + x - 2) / (x - 1);
		LL A = 1 + c1 * (x - 1);
		LL c2 = k;
		printf("%lld\n", c1 + c2);
	}
}