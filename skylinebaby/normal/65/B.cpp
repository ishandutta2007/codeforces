#include<bits/stdc++.h>
using namespace std;
int k[1011];
int main()
{
	int n;
	scanf("%d",&n);
	int flag = 0;
	for(int i = 0;i<n;i++) scanf("%d",&k[i]);
	int nn = 1000;
	for(int i = 0;i<n;i++)
	{
		int m = 9999;
		int a = k[i]/1000;
		int b = (k[i]-a*1000)/100;
		int c = (k[i]-a*1000-b*100)/10;
		int d = k[i]%10;
		for(int j = 0;j<=9;j++)
		{
			int x = k[i]; 
			x -= a*1000;
			x += j*1000;
			if (x<nn) continue;
			m = min(x,m);
		}
		for(int j = 0;j<=9;j++)
		{
			int x = k[i]; 
			x -= b*100;
			x += j*100;
			if (x<nn) continue;
			m = min(x,m);
		}
		for(int j = 0;j<=9;j++)
		{
			int x = k[i]; 
			x -= c*10;
			x += j*10;
			if (x<nn) continue;
			m = min(x,m);
		}
		for(int j = 0;j<=9;j++)
		{
			int x = k[i]; 
			x -= d;
			x += j;
			if (x<nn) continue;
			m = min(x,m);
		}
		nn = m;
		k[i] = m;
		if (nn>2011)
		{
			flag = 1;
			break;
		}	 
	}
	if (flag==1) printf("No solution\n");
	else{
		for(int i = 0;i<n;i++) printf("%d\n",k[i]);
	}
	return 0;
}