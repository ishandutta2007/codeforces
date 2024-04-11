#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _;
ll n, m;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		ll n, m, a, c2 = 0, c5 = 0, k = 1;
		cin >> n >> m;
		a = n;
		// find K
		while (a % 2 == 0) a /= 2, c2++;
		while (a % 5 == 0) a /= 5, c5++;
		while (c2 < c5 && k * 2 <= m) k *= 2, c2++;
		while (c5 < c2 && k * 5 <= m) k *= 5, c5++;
		while (k * 10 <= m) k *= 10;
		// maximize k => maximize n*k
		ll l = 1, r = m, x = 1;
		while (l <= r) {
			ll mid = l + r >> 1;
			if (k * mid <= m) l = mid + 1, x = mid;
			else r = mid - 1;
		}
		cout << n * k * x << "\n";
	}
	return 0;	
}