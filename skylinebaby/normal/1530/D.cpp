#include<bits/stdc++.h>
using namespace std;
int a[212345];
int cnt[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		int k = 0;
		vector<int> g;
		vector<int> h;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) 
		{
			scanf("%d", &a[i]);
			cnt[a[i]] ++;
			if(cnt[a[i]] == 1) k++;
			else h.push_back(i);
		}
		for(int i = 1; i <= n; i++) 
		{
			if(!cnt[i]) g.push_back(i);
		}		
		printf("%d\n", k);
		if(n == k + 1)
		{
			if(g[0] != h[0]) a[h[0]] = g[0];
			else
			{
				for(int i = 1; i <= n; i++)
				{
					if(a[i] == a[g[0]])
					{
						a[i] = g[0];
						break;
					}
				}
			}
		}
		else if(n > k + 1)
		{
			while(true)
			{
				int n = (int)g.size();
				if(n == 2) break;
				if(g[n - 1] == h[n - 1])
				{
					a[h[n - 1]] = g[n - 2];
					g[n - 2] = g[n - 1];
				}
				else a[h[n - 1]] = g[n - 1];
				g.pop_back();
				h.pop_back();
			}
			if(g[0] == h[0])
			{
				a[h[0]] = g[1];
				a[h[1]] = g[0];
			}
			else if(g[1] == h[1])
			{
				a[h[0]] = g[1];
				a[h[1]] = g[0];
			}
			else 
			{
				a[h[0]] = g[0];
				a[h[1]] = g[1];				
			}
		}
		printf("%d", a[1]);
		for(int i = 2; i <= n; i++)
		{
			printf(" %d", a[i]);
		}
		printf("\n");
	}
	return 0;
}