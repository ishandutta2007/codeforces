#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios :: sync_with_stdio(false);
	int n; ll a, b; cin >> n >> a >> b;
	for(int i = 0; i < n; i ++) {
		ll x; cin >> x;
		ll d = x * a / b;
		ll use = b * d / a + (b * d % a == 0 ? 0 : 1);
		cout << x - use << ' ';
	}
	cout << '\n';
	return 0;
}