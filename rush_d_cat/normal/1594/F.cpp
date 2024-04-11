#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		ll s, n, k;
		cin >> s >> n >> k;
		if (s == k) {
			cout << "YES" << "\n"; continue;
		}
		ll s1 = 2 * k;
		ll sum = (n / k) * (2 * k) + (n % k);
		// cout << sum1 << " " << s << "\n";
		cout << (sum > s ? "YES" : "NO") << "\n";
	}
}