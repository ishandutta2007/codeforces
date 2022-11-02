#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		long long now = 1ll * a * b;
		int l = 1, r= 1e6, t = 0;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(1ll * mid * mid * mid > now)r = mid - 1;
			else
			{
				if(1ll * mid * mid * mid == now)
				{
					t = mid;
					break;
				}
				l = mid + 1; 
			}
		}
		if(!t)puts("No");
		else
		{
			if(a % t || b % t)puts("No");
			else puts("Yes");
		}
	}
}