#include<bits/stdc++.h>
using namespace std;
int a[111111];
int main()
{
	int n;
	scanf("%d",&n);
	int tt = -111111;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
		tt = max(tt,a[i]); 
	}
	int x=0,y=0,z=0;
	for(int i = 0;i<n;i++)
	{
		if (a[i]==tt-1) y++;
		if (a[i]==tt) z++; 
		if (a[i]==tt-2) x++;
	}
	if (x==0)
	{
		printf("%d\n",n);
		for(int i = 0;i<n;i++) printf("%d ",a[i]);
		return 0;
	}
	int s = min(x,z);
	if(x+z+y%2>y+x+z-2*s)
	{
		printf("%d\n",y+x+z-2*s);
		for(int i = 0;i<x-s;i++) printf("%d ",tt-2);
		for(int i = 0;i<y+2*s;i++) printf("%d ",tt-1);
		for(int i = 0;i<z-s;i++) printf("%d ",tt);		
	}
	else
	{
		printf("%d\n",x+z+y%2);
		for(int i = 0;i<x+y/2;i++) printf("%d ",tt-2);
		for(int i = 0;i<y%2;i++) printf("%d ",tt-1);
		for(int i = 0;i<z+y/2;i++) printf("%d ",tt);		
	}
	return 0;
}