#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	ll s = 0, x = 0;
	while(n--) {
		ll a;
		cin >> a;
		s += a;
		x ^= a;
	}
	cout << "2\n";
	cout << x << " " << s + x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	    solve();
}