#include<bits/stdc++.h>
using namespace std;
int a[20];
int b[20];
int main()
{
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	int s = (int)log2(n+0.1);
	x--;y--;
	for(int i = 0;i<s;i++)
	{
		a[i]=x%2;
		x=x/2;
		b[i]=y%2;
		y=y/2;
	}
	for(int i = s-1;i>=0;i--)
	{
		if (a[i]!=b[i])
		{
			if (i==s-1) printf("Final!\n");
			else printf("%d\n",i+1);
			break;
		}
	}
	return 0;
}