#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;

	map<long long, int> mp;
	int mx = -2;

	long long ans = 0;

	mp[0] = -1;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (mp.find(sum) != mp.end()) {
			mx = max(mx, mp[sum]);
		}
		mp[sum] = i;

		ans += i - mx - 1;
	}
	cout << ans << "\n";
}