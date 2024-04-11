#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	int k, p;
	cin >>k >> p;
	ll ans = 0LL;
	for (int i = 1; i <= k; i++) {
		string cur = to_string(i);
		string cur2 = to_string(i);
		reverse(cur2.begin(), cur2.end());
		cur = cur + cur2;
		// cout << cur << endl;
		ans = (ans + stoll(cur))%p;
	}
	cout << ans << endl;
	cin >> ans;
}