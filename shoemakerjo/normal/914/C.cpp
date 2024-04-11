#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll mod = 1000000007LL;
ll combos[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// cout << "here " << endl;
	string n;
	cin >> n;
	int k;
	cin >> k;
	bool ok[1001];
	// int nc = 0;
	ok[0] = false;
	for (int i = 1; i <= 1000; i++) {
		// cout << "i   " << i << endl;
		int sc = 0;
		int cur = i;
		while (cur > 1) {
			sc++;
			cur = __builtin_popcount(cur);
		}
		if (sc == k-1) {
			ok[i] = true;
			// cout << "this val  " << i << endl;
		}
		else ok[i] = false;
		// if (sc == k && i <= 507) nc++;
	}
	if (k == 0) {
		cout << 1 << endl;
		return 0;
	}
	
	for (int i = 0; i <= 1000; i++) {
		combos[i][0] = 1LL;
		combos[i][1] = i;
	}
	for (int i = 1; i <= 1000; i++) {
		combos[0][i] = 0LL;
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 2; j <= i; j++) {
			combos[i][j] = (combos[i-1][j-1] + combos[i-1][j])%mod;

		}
		for (int j = i+1; j <= 1000; j++) {
			combos[i][j] = 0LL;
		}
	}
	ll ans = 0LL;
	int oseen = 0;
	int le = n.length();
	for (int i = 0; i < le; i++) {
		if (n[i] == '0') continue;
		int wk = le-i-1;
		for (int j = 0; j <= 1000; j++) {
			if (j-oseen < 0) continue;
			if (ok[j]) {
				ans = (ans+combos[wk][j-oseen])%mod;
				// cout << "added for " << j << ":  " << combos[wk][j-oseen] << endl;
			}
		}
		oseen++;
	}
	if (ok[oseen]) {
		ans = (ans+1LL)%mod;
		// cout << "lgood " << endl;
	}
	if (k == 1) ans  = (ans + mod - 1LL)%mod;
	cout << ans << endl;
	// cout << nc << endl;
	cin >> ans;
}