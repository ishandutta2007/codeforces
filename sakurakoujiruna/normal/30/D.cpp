#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;

const int N = 2e5L + 11;
ll x[N], sx[N];
ll sqr(ll x) { return x * x; }

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(0);

	int n, k; cin >> n >> k;
	for(int i = 1; i <= n + 1; i ++)
		cin >> x[i];
	ll y; cin >> y;
	ll mi = *min_element(x + 1, x + n + 1);
	ll ma = *max_element(x + 1, x + n + 1);

	if(k == n + 1)
		cout << ma - mi + min(sqrt(sqr(mi - x[n + 1]) + y * y),
			sqrt(sqr(ma - x[n + 1]) + y * y)) << '\n';
	else {
		db ans = 1e9L;
		copy(x, x + n + 1, sx);
		sort(sx + 1, sx + n + 1);

		auto solve = [&](int l, int r) {
			if(l > r) return 0.0;
			ll mi = sx[l], ma = sx[r];
			if(sx[l] <= x[k] && x[k] <= sx[r])
				return ma - mi + min(ma - x[k] + sqrt(sqr(mi - x[n + 1]) + y * y),
					x[k] - mi + sqrt(sqr(ma - x[n + 1]) + y * y));
			else
				return ma - mi + min(sqrt(sqr(mi - x[n + 1]) + y * y),
					sqrt(sqr(ma - x[n + 1]) + y * y));
		};

		for(int l = 0; l <= n; l ++)
			ans = min(ans, solve(1, l) + solve(l + 1, n));
		cout << ans << '\n';
	}
}