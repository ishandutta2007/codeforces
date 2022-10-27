#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int T;
LL a, b, n;
int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%lld%lld%lld", &a, &b, &n);
		for (int i = 1;; i ++) {
			if (a > b) swap(a, b);
			a += b;
			if (a > n) {
				printf("%d\n", i); break;
			}
		}
	}
}