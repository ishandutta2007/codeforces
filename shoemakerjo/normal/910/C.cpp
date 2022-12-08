#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	string cur;
	ll fa[10];
	bool fi[10];
	bool take[10];
	for (int i = 0; i < 10; i++) {
		fa[i] = 0LL;
		fi[i] = true;
		take[i] = false;
	}
	for (int i = 0; i < n; i++) {
		cin >> cur;
		ll mult = 1LL;
		fi[cur[0]-'a'] = false;
		for (int i = cur.length()-1; i >= 0; i--) {
			int spot = cur[i]-'a';
			fa[spot] += mult;
			mult *= 10LL;
		}
	}
	// for (int j = 0; j < 10; j++) {
	// 	cout << j << "  " << fa[j]  << endl;
	// }
	ll ans = 0LL;
	for (int i = 0; i <= 9; i++) {
		ll mx = -1;
		int spot = 0;
		for (int j = 0; j < 10; j++) {

			if (take[j]) continue;
			if (fa[j] > mx && (i != 0 || fi[j])) {
				mx = fa[j];
				spot = j;
			}
		}
		// cout << i << " i   " << mx << "    -   " << spot << endl;
		ans += (i+0LL)*mx;
		take[spot] = true;
	}
	cout << ans << endl;
	cin >> ans;
}