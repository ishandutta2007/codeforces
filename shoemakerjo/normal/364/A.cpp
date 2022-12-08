#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int a;
	cin >> a;
	string s;
	cin >> s;
	int prefix[s.length()];
	prefix[0] = s[0]-'0';
	for (int i = 1; i < s.length(); i++) {
		prefix[i] = prefix[i-1] + s[i]-'0';
	}
	// if (a == 0) {
	// 	cout << 0 << endl;
	// 	return 0;
	// }
	map<int, ll> vals;
	ll ct = 0;
	for (int i = 1; i*i <= a; i++) {
		if (a == 0) break;
		if (a% i == 0) {
			vals[i] = 0;
			vals[a/i] = 0;
		}
	}
	// cout << "here\n";
	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			int cur = prefix[j];
			if (i >= 1) cur = prefix[j] - prefix[i-1];
			// cout << cur << endl;
			// if (cur  == 0) cout << "j:  " << j << " " << i  << " " << prefix[0] << endl;
			if (cur == 0 && a == 0) ct++;
			if (cur == 0) continue;
			if (a%cur == 0) {
				vals[cur]++;
			}
		}
	}
	// cout << "here\n";
	ll ans = 0;
	if (a == 0) {
		cout << ct*s.length()*(s.length()-1) + 2LL*ct*s.length() - ct*ct << endl;
		// cin >> ans;
		return 0;
	}
	for (int i = 1; i*i <= a; i++) {
		if (a%i!=0) continue;
		ans += 2*vals[i]*vals[a/i];
		if (i*i == a) ans -= vals[i]*vals[i];
	}
	cout << ans << endl;
	cin >> ans;
	
}