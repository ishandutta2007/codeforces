#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios :: sync_with_stdio(false);
	int t; cin >> t;
	while(t --) {
		ll n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;
		auto check = [&](ll a1, ll a2) {
			ll a[3] = {0, a1, a2};
			ll mi = *min_element(a, a + 3);
			for(int i = 0; i < 3; i ++)
				a[i] -= mi;
			ll sum = accumulate(a, a + 3, 0LL);
			if(*max_element(a, a + 3) + (k - sum) / 3 <= n / 3 &&
				(sum - k) % 3 == 0 && sum <= k)
				return true;
			return false;
		};
		if(n % 3 == 0 &&
			(check(d1, d1 + d2) || check(d1, d1 - d2) ||
			check(-d1, -d1 + d2) || check(-d1, -d1 - d2)))
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}