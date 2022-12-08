#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool issquare(ll x) {
	ll v = round(sqrt(x));
	return v*v == x;
}

int main() {
	int n;
	cin >> n;
	vector<int> dig;
	int ans = -1;
	while (n > 0) {
		dig.push_back(n%10);
		n /= 10;
	}
	reverse(dig.begin(), dig.end());
	int k = dig.size();
	for (int mask = 1; mask < (1 << k); mask++) {
		vector<int> cur;
		int ct = 0;
		for (int i = 0; i < k; i++) {
			if (mask & (1 << i)) {
				cur.push_back(dig[i]);
				ct++;
			}
		}
		ct = k-ct; //this is the cost
		if (cur[0] == 0) continue;
		ll val = 0LL;
		for (int i = 0; i < cur.size(); i++) {
			val = val*10LL + cur[i];
		}
		if (issquare(val)) {
			if (ans == -1 || ct < ans) {
				ans = ct;
			}
		}
	}
	cout << ans << endl;
	cin >> n;
}