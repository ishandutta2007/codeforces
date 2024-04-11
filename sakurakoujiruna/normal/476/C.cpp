#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll Mod = (ll)1e9 + 7;

int main()
{
	ios :: sync_with_stdio(false);
	ll a, b;
	cin >> a >> b;

	ll ans = 0;
	for(ll i = 1; i < b; i ++)
	{
		ans += i * a;
		ans %= Mod;
		ans += a * (a + 1) / 2 % Mod * i % Mod * b % Mod;
		ans %= Mod;
	}
	cout << ans << '\n';
	return 0;
}