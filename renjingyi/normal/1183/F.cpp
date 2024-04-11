#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int calc(const int &n)
{
	int x = a[n], y = 0, sum = x;
	bool gety = 0;
	for(int i = n - 1; i >= 1; i --)
	{
		if(!gety && x % a[i] != 0)
		{
			y = a[i];
			sum += y;
			gety = 1;
		}
		else if(gety && x % a[i] != 0 && y % a[i] != 0)
			return sum + a[i];
	}
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q --)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		n = unique(a + 1, a + n + 1) - a - 1;
		if(n == 1)
		{
			cout << a[1] << '\n';
			continue;
		}
		int ans1 = a[n], ans2 = a[n];
		for(int i = n - 1; i >= 1; i --)
			if(a[n] % a[i])
			{
				ans2 += a[i];
				break;
			}
		int ans3 = max(calc(n), calc(n - 1));
		cout << max(ans1, max(ans2, ans3)) << '\n';
	}
	
	return 0;
}