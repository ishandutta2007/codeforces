#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, m, a[N], sum;

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get(), sum += a[i];
	sort(a + 1, a + 1 + n);
	m = get();
	for(int i = 1; i <= m; i++) {
		int x = get(), y = get();
		if(x > a[n]) printf("%lld\n", x - a[n] + max(y - (sum - a[n]), 0ll));
		else if(x < a[1]) printf("%lld\n", max(y - (sum - a[1]), 0ll));
		else {
			int pos = lower_bound(a + 1, a + 1 + n, x) - a, ans = 0x3f3f3f3f3f3f3f3f;
			ans = min(ans, max(0ll, x - a[pos]) + max(0ll, y - (sum - a[pos])));
			pos = upper_bound(a + 1, a + 1 + n, x) - a - 1;
			ans = min(ans, max(0ll, x - a[pos]) + max(0ll, y - (sum - a[pos])));
			printf("%lld\n", ans);
		}
	}
	return 0;
}