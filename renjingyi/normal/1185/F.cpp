#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 9;
const int oo = 2e9 + 5;
int cnt[1 << 9], c1[1 << 9], c2[1 << 9], pos1[1 << 9], pos2[1 << 9];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		int f;
		cin >> f;
		int now = 0;
		while(f --)
		{
			int b;
			cin >> b;
			now |= 1 << b - 1;
		}
		cnt[now] ++;
	}
	for(int i = 0; i < (1 << 9); i ++)
		c1[i] = c2[i] = oo;
	for(int i = 1; i <= m; i ++)
	{
		int tmp, r;
		cin >> tmp >> r;
		int now = 0;
		while(r --)
		{
			int a;
			cin >> a;
			now |= 1 << a - 1;
		}
		if(tmp < c1[now])
		{
			c2[now] = c1[now];
			pos2[now] = pos1[now];
			c1[now] = tmp;
			pos1[now] = i;
		}
		else if(tmp < c2[now])
		{
			c2[now] = tmp;
			pos2[now] = i;
		}
	}
	for(int i = (1 << 9) - 1; i >= 0; i --)
		for(int j = 0; j < i; j ++)
			if((i & j) == j)
				cnt[i] += cnt[j];
	int mxt = 0, mn = oo, x = 0, y = 0;
	for(int i = 0; i < (1 << 9); i ++)
	{
		if(c1[i] < oo && c2[i] < oo)
		{
			if(cnt[i] > mxt || cnt[i] == mxt && c1[i] + c2[i] < mn)
			{
				mxt = cnt[i];
				mn = c1[i] + c2[i];
				x = pos1[i];
				y = pos2[i];
			}
		}
		for(int j = i + 1; j < (1 << 9); j ++)
			if(c1[i] < oo && c1[j] < oo)
			{
				if(cnt[i | j] > mxt || cnt[i | j] == mxt && c1[i] + c1[j] < mn)
				{
					mxt = cnt[i | j];
					mn = c1[i] + c1[j];
					x = pos1[i];
					y = pos1[j];
				}
			}
	}
	cout << x << " " << y << endl;
	
	return 0;
}