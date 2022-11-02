#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 511;
int a[N];

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	ll ans = 1e18L;
	auto check = [&](int s) {
		if(s == 0) return;
		ll sum = 0;
		for(int i = 0; i < n; i ++) {
			int l = (a[i] + s) / (s + 1);
			int r = a[i] / s;
			if(l > r) return;
			sum += l;
		}
		ans = min(ans, sum);
	};

	for(int i = 1; ; i = a[0] / (a[0] / (i + 1))) {
		check(a[0] / i - 1); check(a[0] / i);
		if(i == a[0]) break;
	}
	cout << ans << '\n';
}