#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int t, n, k;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d",&n,&k);
		int mx = 1;
		for (int i = 1; i * i <= n; i ++) {
			if (n % i == 0) {
				if (i <= k) mx = max(mx, i);
				if (n/i <= k) mx = max(mx, n/i);
			}
		}
		printf("%d\n", n / mx);
	}
}