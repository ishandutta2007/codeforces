#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll calc(ll x) {
	string bin = "";
	ll cur = x;
	while (cur > 0LL) {
		if (cur % 2LL == 0LL) {
			bin = "0" + bin;
		}
		else {
			bin = "1" + bin;
		}
		cur/=2LL;
	}
	ll ans = 0LL;
	int n = bin.length();
	for (int i = 0; i <= n-2; i++) {
		ans += i+0LL; //should add for less than me
	}
	// cout << "before run through:   " << ans << endl;
	for (int i = 1; i < n; i++) {
		if (bin[i] == '0') break; //break this
		//add 1 by letting this guy be the 0
		ans += 1LL;
	}
	int oc = 0;
	for (int i = 0; i < n; i++) {
		if (bin[i] == '0') oc++;
	}
	if (oc==1) ans += 1LL;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a, b;
	cin >> a >> b;
	ll ans = calc(b); //calc for 0 to me
	// cout << "middle ans  " << ans << endl;
	ans -= calc(a-1LL);
	cout << ans << endl;
	cin >> a;
}