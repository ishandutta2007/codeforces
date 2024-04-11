#include<bits/stdc++.h>
using namespace std;
int a[111111];
char b[111111];
main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	cin >> b;
	int ll = -1000000000;
	int rl = 1000000000;
	int lr = -1000000000;
	int rr = 1000000000; 
	for(int i = 4;i<n;i++)
	{
		if (b[i]=='0')
		{
			if (b[i-1]=='0')
			{
				int t = -1000000001;
				for(int j = i-4;j<=i;j++)
				{
					t = max (t,a[j]);
				}
				rl = min(rl,t);	
			}
			else 
			{
				int t = 1000000001;
				for(int j = i-4;j<=i;j++)
				{
					t = min (t,a[j]);
				}
				rr = min (rr,t-1);
				i = i + 3;					
			}
		}
		if (b[i]=='1')
		{
			if (b[i-1]=='1')
			{
				int t = 1000000001;
				for(int j = i-4;j<=i;j++)
				{
					t = min (t,a[j]);
				}
				lr = max(lr,t);	
			}
			else 
			{
				int t = -1000000001;
				for(int j = i-4;j<=i;j++)
				{
					t = max (t,a[j]);
				}
				ll = max (ll,t+1);		
				i = i + 3;			
			}	
		}
	}
	lr = max(ll,lr);
	printf("%d %d\n",ll,lr);
	return 0;
}