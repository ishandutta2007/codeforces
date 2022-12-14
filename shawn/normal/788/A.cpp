#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

typedef long long ll;
const ll inf = 0x7f7f7f7f7f7f7f7fll;
const int N = 1e5 + 10;
ll a[N], b[N], c[N], n;

ll calc(ll *x) {
	ll re = 0, t = 0;
	for (int i = 1; i < n; i ++) {
		t += x[i];
		re = max(re, t);
		if (t < 0) t = 0;
	}
	return re;
}

int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 1; i < n; i ++) b[i] = abs(a[i] - a[i + 1]) * ((i & 1) ? 1 : -1);
	for (int i = 1; i < n; i ++) c[i] = abs(a[i] - a[i + 1]) * ((i & 1) ? -1 : 1);
	printf("%lld\n", max(calc(b), calc(c)));
	return 0;
}