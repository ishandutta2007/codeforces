//In the name of God
// Break through! i screamed forth from my soul!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s;
string to_str(ll x) {
	string s = "";
	while (x) {
		s += (x % 10) + '0';
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
ll gcd(ll x, ll y) {
	char ch = 'A' + (x < y);
	if (x < y)
		swap(x, y);
	while (y) {
		ll num = x / y;
		x %= y;
		swap(x, y);
		if (!y)
			--num;
		s += to_str(num);
		s += ch;
		ch = 'A' + 'B' - ch;
	}
	return x;
}
int main() {
	ll x, y; cin >> x >> y;
	if (gcd(x, y) != 1) {
		cout << "Impossible\n";	
	} else {
		cout << s << '\n';	
	}
	return 0;
}