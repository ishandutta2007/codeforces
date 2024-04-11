#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n, k, t;
	cin >> n >> k >> t;
	ll ans = min(n, t) - max(0LL, t-k);
	cout << ans << endl;
	// cin >> n;
}