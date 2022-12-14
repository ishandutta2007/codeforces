#include <bits/stdc++.h>

using namespace std;



#define N 33



int c[N], n, m;



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i ++) scanf("%d", &c[i]);

	for (int i = 1; i < n; i ++) c[i] = min(c[i], c[i-1] << 1);

	for (int i = n - 2; i >= 0; i --) c[i] = min(c[i], c[i+1]);



	int G = 1 << (n - 1);

	int t = m / G;

	long long tmp = 1ll * t * c[n-1];

	long long ans = 1ll << 60;

	m %= G;

	for (int i = n - 1; i >= 0; i --) {

		if (!m) {

			ans = min(ans, tmp);

			break;

		}

		if (m >= (1 << i)) tmp += c[i], m -= (1 << i);

		if (!m) ans = min(ans, tmp);

		else ans = min(ans, tmp + c[i]);

	}

	printf("%I64d\n", ans);



	return 0;

}