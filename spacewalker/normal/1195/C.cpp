#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n; scanf("%d", &n);
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
	vector<ll> ts(n), bs(n), ne(n);
	ts[0] = a[0];
	bs[0] = b[0];
	ne[0] = 0;
	for (int i = 1; i < n; ++i) {
		ts[i] = max(bs[i - 1], ne[i - 1]) + a[i];
		bs[i] = max(ts[i - 1], ne[i - 1]) + b[i];
		ne[i] = max(ts[i - 1], max(bs[i - 1], ne[i - 1]));
	}
	printf("%lld\n", max(ts[n - 1], max(bs[n - 1], ne[n - 1])));
	return 0;
}