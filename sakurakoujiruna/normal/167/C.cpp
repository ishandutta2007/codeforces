#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool solve(ll a, ll b) {
	if(a > b) return solve(b, a);
	if(a == 0) return false;
	if(!solve(b % a, a)) return true;
	return ((b / a) % (a + 1)) & 1 ^ 1;
}

int main() {
	ios :: sync_with_stdio(false);
	int t; cin >> t;
	while(t --) {
		ll a, b;
		cin >> a >> b;
		cout << (solve(a, b) ? "First" : "Second") << '\n';
	}
	return 0;
}