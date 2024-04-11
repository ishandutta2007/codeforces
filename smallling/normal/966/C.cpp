#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int cnt[64];
long long a[64][N], b[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		long long x;
		scanf("%I64d", &x);
		for(int j = 59; j >= 0; j--)
			if((x >> j) & 1)
			{
				a[j][++*a[j]] = x;
				break;
			}
	}
	long long nowv = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 60; j++)
			if(cnt[j] < *a[j])
			{
				long long nowvv = a[j][cnt[j] + 1];
				if((nowvv ^ nowv) > nowv)
				{
					nowv ^= nowvv;
					b[i] = a[j][++cnt[j]];
					break;
				}
			}
		if(!b[i])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i = 1; i <= n; i++)
		printf("%I64d ", b[i]); 
}