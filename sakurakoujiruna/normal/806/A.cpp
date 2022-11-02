#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

bool check(ll a, ll b, ll c, ll d) {
	if(a > c) return 0;
	if(b > d) return 0;
	if(b - a > d - c) return 0;
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll g = __gcd(c, d);
		c /= g; d /= g;
		
		ll l = 1, r = 4e9L + 1;
		while(l + 1 < r) {
			ll m = (l + r) / 2;
			if(check(a, b, c * (m - 1), d * (m - 1)))
				r = m;
			else
				l = m;
		}
		if(check(a, b, c * l, d * l))
			cout << l * d - b << '\n';
		else
			cout << "-1\n";
	}
	return 0;
}