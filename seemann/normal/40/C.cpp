#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#define ll long long int

using namespace std;



int main()
{
	ll n, m, x, y;
	cin >> n >> x >> m >> y;
	if (x > y) swap(x, y);
	ll ans = 1 + n + m;
	ll d = abs(x - y);
	ans += (max(min(x + n, y) - max((y - m), x), (ll)0)) * (max(min(x + n, y) - max((y - m), x), (ll)0));
	for (ll i = 0; i < min(n - d, m); i++)
	{
		ans += (min(m, d + n) - 1) * 2 - i * 2;
	}
	
	for (ll i = 0; i < min(m - d, n); i++)
	{
		ans += (min(n, d + m) - 1) * 2 - i * 2;
	}
	ans -= max(min(n - d, m), (ll)0) * max(min(m - d, n), (ll)0) * 2;


	cout << ans;
}