#include <bits/stdc++.h>
#define M 400005
#define mod 1000000007
#define PB push_back
#define MP std::make_pair
#define FI first
#define SE second
typedef long long ll;
ll t, n;
ll read() {
	char c = getchar(); ll ans = 0;
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
	return ans;
}
void Write(ll x) {
	if (x < 10) putchar(x + '0');
	else Write(x / 10), putchar(x % 10 + '0');
}
ll calc(ll n) {
	ll ans = 0;
	while (n) {
		if (n == 4) return ans + 3;
		if (n / 2 & 1) ans += n / 2, n /= 2, n--;
		else ans++, n -= 2;
	}
	return ans;
}
int main() {
	t = read();
	while (t--) {
		n = read();
		if (n & 1) Write(n - calc(n - 1)), putchar('\n');
		else Write(calc(n)), putchar('\n');
	}
	return 0;
}