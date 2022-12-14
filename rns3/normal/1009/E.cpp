#include <bits/stdc++.h>

using namespace std;



#define N 1010101

const int mod = 998244353;



int a[N], n;



int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

	int ans = 0;

	int now = (mod + 1) / 2;

	for (int k = n; k >= 1; k --) {

		ans = (ans + (1ll * now * (n - k + 2) % mod) * a[k]) % mod;

		now = (now << 1) % mod;

	}

	printf("%d\n", ans);



	return 0;

}