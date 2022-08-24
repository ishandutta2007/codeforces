#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int c[3], n[3], p[3];
ll r;

bool works (ll x)
{
	ll tot = 0;
	for (int i = 0; i < 3; i++)
		tot += max (0LL, p[i] * (c[i] * x - n[i]));
	return tot <= r;
}

int main()
{
	string str;
	cin >> str;
	
	c[0] = c[1] = c[2] = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'B')
			c[0]++;
		else if (str[i] == 'S')
			c[1]++;
		else
			c[2]++;
	}
	
	for (int i = 0; i < 3; i++)
		cin >> n[i];
	for (int i = 0; i < 3; i++)
		cin >> p[i];
	cin >> r;
	
	ll lo = 0, hi = 1e13;
	while (lo < hi)
	{
		ll mid = (lo + hi + 1) / 2;
		if (works (mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	cout << lo << "\n";
	return 0;
}