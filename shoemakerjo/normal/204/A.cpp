#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll count(ll num, bool ok) {
	char buffer[30];
	_i64toa(num, buffer, 10);
	string cur = buffer;
	ll ans = 0LL;
	ll mult = 1LL;
	for (int i = 1; i < cur.length(); i++) {
		if (i > 2) {
			mult*=10LL;
		}
		ans += mult*9LL;
	}
	if (cur.length() > 2) {
		mult*=10LL;
	}
	
	for (int i = 1; i < cur[0]-'0'; i++) {
		ans += mult;
	}
	if (cur.length() <= 2) {
		if (cur[cur.length()-1]-'0' > cur[0]-'0') {
			ans++;
		}
		else if (cur[cur.length()-1]-'0' == cur[0]-'0' && ok) ans++;
		return ans;
	}
	ll mid = stoll(cur.substr(1, cur.length()-2));
	ll poss = mid;
	if (cur[cur.length()-1]-'0' > cur[0]-'0') {
		poss++;
	}
	else if (cur[cur.length()-1]-'0' == cur[0]-'0' && ok) poss++;
	ans += poss;
	return ans;
}

int main() {
	ll l, r;
	cin >> l >> r;
	ll ans = count(r, true);
	// cout << "ans:  " << ans << endl;
	ans -= count(l, false);
	cout << ans << endl;
	// cin >> l;
}