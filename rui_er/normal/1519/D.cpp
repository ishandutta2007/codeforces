#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e3+5;

ll n, a[N], b[N], ans, delta;

int main() {
	scanf("%lld", &n);
	for(ll i=1;i<=n;i++) scanf("%lld", &a[i]);
	for(ll i=1;i<=n;i++) scanf("%lld", &b[i]);
	for(ll i=1;i<=n;i++) ans += a[i] * b[i];
	for(ll M=1;M<=n;M++) {
		ll qwq = 0;
		for(ll dt=0;dt<=n;dt++) {
			ll L = M - dt, R = M + dt;
			if(L < 1 || R > n) break;
			qwq += (a[L] - a[R]) * (b[R] - b[L]);
			delta = max(delta, qwq);
		}
	}
	for(ll M=1;M<n;M++) {
		ll qwq = 0;
		for(ll dt=0;dt<=n;dt++) {
			ll L = M - dt, R = M + 1 + dt;
			if(L < 1 || R > n) break;
			qwq += (a[L] - a[R]) * (b[R] - b[L]);
			delta = max(delta, qwq);
		}
	}
	ans += delta;
	printf("%lld\n", ans);
	return 0;
}