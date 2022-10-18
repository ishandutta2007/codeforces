#include<bits/stdc++.h>
using namespace std;
int a[212345];
int b[212345];
int c[212345];
int d[212345];
int n;
int check(int k)
{
	if(k > n) return 1;
	for(int i = 0; i < n; i++)
	{
		c[i] = a[i];
		d[i] = b[i];
	}
	for(int i = n; i < n + k; i++)
	{
		c[i] = 100;
		d[i] = 0;
	}
	int z = (n + k) / 4;
	sort(c, c + n + k);
	sort(d, d + n + k);
	int suma = 0;
	int sumb = 0;
	for(int i = z; i < n + k; i++)
	{
		suma += c[i];
		sumb += d[i];
	}	
	if (suma >= sumb) return 1;
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 0; i < n; i++) scanf("%d", &b[i]);
		int ans = 0;
		if(check(0))
		{
			printf("0\n");
			continue;
		}
		int f = 17;
		while(f--)
		{
			if(!check(ans + (1 << f)))
			{
				ans = ans + (1 << f);
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}