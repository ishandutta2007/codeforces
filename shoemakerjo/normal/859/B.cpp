#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll N;
	cin >> N;
	ll ans = 2*(N+1);
	for (ll i = 1; i <= N; i++) {
		
		ans = min(ans, 2LL*(i + (N+i-1)/i));
		
	}
	cout << ans << endl;
	// cin >> ans;
}