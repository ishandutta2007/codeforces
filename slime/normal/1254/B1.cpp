#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
using namespace std;
int n;
int a[maxn];
bool bpr[maxn];
ll b[maxn];
ll cal(ll x) {
	ll ans = 0;
	for (int i = 1; i <= n; i++) 
		b[i] = a[i] % x;
	for (int i = 1; i <= n; i++) {
		ans += min(b[i], x - b[i]);
		b[i + 1] = (b[i + 1] + b[i]) % x;
	}
	return ans;
}
int main() {
	cin >> n;
	ll s = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), 
		s += a[i];
	for (int j = 0; j < maxn; j++)
		bpr[j] = 1;
	for (int j = 2; j < maxn; j++)
		if (bpr[j])
			for (int i = 2; i * j < maxn; i++)
				bpr[i * j] = 0;
	ll ans = 2e18;
	for (int j = 2; j < maxn; j++)
		if (s % j == 0) {
			ans = min(ans, cal(j));
			while (s % j == 0)
				s /= j;
		}
	if (s != 1) ans = min(ans, cal(s));
	if (ans >= 2e18 - 10) ans = -1;
	printf("%lld\n", ans);
	return 0;
}