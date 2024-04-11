#include<bits/stdc++.h>
using namespace std;
int a[512345];
long long s[512345];
int p[512345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		int x;
		scanf("%d", &x);
		vector<int> v;
		v.push_back(0);
		int k = 1;
		for(int i = 0; i < n; i++) 
		{
			a[i] -= x;
			s[i + 1] = s[i] + a[i]; 
		}
		for(int i = 2; i <= n; i++)
		{
			if(s[i] >= s[v[0]]) p[i] = -1;
			else
			{
				for(int j = k - 1; j >= 0; j--)
				{
					if(s[v[j]] > s[i])
					{
						p[i] = v[j]; 
						break;
					}
				}				
			}
			if(s[i - 1] >= s[v[0]])
			{
				k = 1;
				v[0] = i - 1;
			}
			else
			{
				for(int j = k - 1; j >= 0; j--)
				{
					if(s[v[j]] > s[i - 1])
					{
						if(j + 1 == v.size())
						{
							v.push_back(i - 1);						
						}
						else
						{
							v[j + 1] = i - 1;					
						}
						k = j + 2;
						break;
					}
				}				
			}
		}
		//for(int i = 2; i <= n; i++) printf("p[%d] = %d\n", i, p[i]);
		int ans = 0;
		int last = 0;
		for(int i = 2; i <= n; i++)
		{
			if(p[i] >= last)
			{
				last = i;
				ans++;
			}
		}
		printf("%d\n", n - ans);
		
	}
	return 0;
}