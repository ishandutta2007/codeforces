#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n)
{
	ll left = 0, right = 1e6;
	while(left + 1 < right)
	{
		ll mid = (left + right) / 2;
		if(mid * (mid - 1) / 2 > n)
			right = mid;
		else
			left = mid;
	}
	if(left * (left - 1) / 2 == n)
		return left;
	return -1;
}

const string Imp = "Impossible";

int main()
{
	ios :: sync_with_stdio(false);
	ll a00, a01, a10, a11;
	cin >> a00 >> a01 >> a10 >> a11;
	ll c0 = solve(a00);
	ll c1 = solve(a11);

	if(a01 + a10 == 0 && c0 == 1)
		c0 = 0;
	else if(a01 + a10 == 0 && c1 == 1)
		c1 = 0;

	string ans = "";
	if(c0 == -1 || c1 == -1)
	{
		cout << Imp << '\n';
		return 0;
	}
	else if(a01 + a10 != c0 * c1)
	{
		cout << Imp << '\n';
		return 0;
	}
	
	ll use0 = 0;
	int n = c0 + c1;
	for(int i = 0; i < n; i ++)
	{
		if(c0 && c1 <= a01)
		{
			use0 ++;
			c0 --;
			a01 -= c1;
			ans += '0';
		}
		else
		{
			c1 --;
			ans += '1';
		}
	}
	
	cout << ans << '\n';
	return 0;
}