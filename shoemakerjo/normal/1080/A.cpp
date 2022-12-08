#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	ll ans = 0LL;
	ans += (2*n+k-1)/k;
	ans += (5*n+k-1)/k;
	ans += (8*n+k-1)/k;
	cout << ans << endl;
}