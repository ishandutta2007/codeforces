#include<bits/stdc++.h>
using namespace std;
int a[1234];
int b[1234];
int c[1234];
int d[1234];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%d",&a[i]);
	for(int i = 0;i<n;i++) scanf("%d",&b[i]);
	int s = n;
	int k = n;
	int f = 0;
	while(k)
	{
		int flag = 0;
		for(int i = 0;i<n;i++)
		{
			if(a[i]==0&&b[i]==0&&d[i]==0) 
			{
				flag = 1;
				d[i] = s;
				k--;
			}
		}		
		if(flag == 0) 
		{
			f = 1;
			break; 
		}
		for(int i = 0;i<n;i++)
		{
			if(d[i]==s)
			{
				c[i] = s;
				for(int j = 0;j<i;j++)
				{
					if(d[j]==0)
					{
						b[j]--;
					}
				}
				for(int j = i+1;j<n;j++)
				{
					if(d[j]==0)
					{
						a[j]--;
					}
				}
			}
		}
		s--;
	} 
	if(f)
	{
		printf("NO\n");
		return 0;
	}	
	printf("YES\n%d",c[0]);
	for(int i = 1;i<n;i++)
	{
		printf(" %d",c[i]);
	}
	printf("\n");
	return 0;
}