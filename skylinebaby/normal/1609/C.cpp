#include<bits/stdc++.h>
using namespace std;
int prime[1123456];
int a[212345];
int sm[212345];
int main()
{

	int t;
	scanf("%d", &t);
	for(int i = 2; i <= 1000000; i++) prime[i] = 1;
	for(int i = 2; i <= 1000000; i++) for(int j = 2; i * j <= 1000000; j++) prime[i * j] = 0;
	while(t--)
	{
		int n, e;
		scanf("%d %d", &n, &e);
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if(x == 1) a[i] = 0;
			else if(prime[x]) 
			{
				a[i] = 1;
				sum ++;	
			}
			else a[i] = 2;
		}
		long long ans = 0;
		for(int i = e; i < n; i++) a[i] += a[i - e];
		/*for(int i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");*/
		for(int i = 0; i < e; i++)
		{
			int k = 0;
			int l = 1;
			int m = 0;
			for(int j = i; j < n; j += e)
			{
				if(a[j] == k)
				{
					l ++;
				}
				if(a[j] == k + 1)
				{
					m ++;
					ans += l;
				}
				if(a[j] == k + 2)
				{
					k ++;
					l = m;
					m = 1;
					ans += l;
				}
				if(a[j] > k + 2)
				{
					k = a[j];
					l = 1;
					m = 0; 
				}
			}
			//printf("%d %d\n", i, ans);
		}
		printf("%lld\n", ans - sum);
	}
	return 0;
}