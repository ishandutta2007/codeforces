#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll read() {
	ll x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

const ll maxn = 1e6 + 10;

ll n, ans[maxn], a[maxn], tot;
char s[maxn];

int main() {
	n = read();
	scanf("%s", s + 1);
	for (ll i = 1; i <= n; i++) if (s[i] == 'D') a[++ a[0]] = i;
	for (ll i = 1; i <= a[0]; i++) {
		tot += (a[i] - i) * 2;
		ans[i] = i + tot; 
	}
	
	a[0] = tot = 0;
	for (ll i = n; i; i --) if (s[i] == 'U') a[++ a[0]] = i;
	for (ll i = 1; i <= a[0]; i ++) {
		ll j = n - i + 1;
		tot += (j - a[i]) * 2;
		ans[j] = i + tot;
	}
	
	for (ll i = 1; i <= n; i ++) printf("%I64d ", ans[i]);
	return 0;
}