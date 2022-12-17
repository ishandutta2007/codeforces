#include <bits/stdc++.h>
using namespace std;
long long con[25];
long long calc(long long v)
{
	long long ret = 0, now = 10;
	for(int i = 1; i <= 15; i ++)
	{
		if(v < now)
			return con[i] + (v - now + 1) * i;
		now *= 10;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	long long k;
	cin >> k;
	long long now = 1;
	for(int i = 1; i <= 15; i ++)
	{
		con[i] = con[i - 1] + 9 * i * now;
		now *= 10;
	}
	long long l = 1, r = 1e15;
	while(l < r)
	{
		long long mid = l + r >> 1;
		if(calc(mid) < k)
			l = mid + 1;
		else
			r = mid;
	}
	long long x = l, t = calc(l) - k;
	for(int i = 1; i <= t; i ++)
		x /= 10;
	cout << x % 10 << endl;
	
	
	return 0;
}