#include<bits/stdc++.h>
using namespace std;

#define N 1000010
int n, p[N];
typedef long long ll;
ll a[N];
int c[N], d[N];
const int mod = 1e9 + 7;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%I64d", &a[i]);
	for (int i = 2; i <= n; i ++) scanf("%d", &p[i]);
	for (int i = n; i >= 2; i --) a[p[i]] += a[i];
	for (int i = 2; i <= n; i ++) {
		a[i] = a[1] / __gcd(a[i], a[1]);
		if (a[i] <= n) c[a[i]] ++;
	}
	c[1] = 1;
	for (int i = n; i >= 1; i --) for (int j = 2 * i; j <= n; j += i) c[j] += c[i];
	int ans = 0;
	d[1] = 1;
	for (int i = 1; i <= n; i ++) if (c[i] == i) {
		ans = (ans + d[i]) % mod;
		for (int j = 2 * i; j <= n; j += i) d[j] = (d[j] + d[i]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}