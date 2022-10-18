#include<bits/stdc++.h>
using namespace std;
int pr[100];
int yy[100];
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	scanf("%d %d",&a,&b);
	int pos = 0;
	for(int i = 2;i*i<=a+1;i++)
	{
		if (a%i==0) 
		{
			pr[pos] = i;
			yy[pos++] = 1;
			while(a%i==0)
			{
				a=a/i;
			}
		}
	}
	if (a!=1) 
	{
		pr[pos] = a;
		yy[pos++] = 1;		
	}
	for(int i = 2;i*i<=b+1;i++)
	{
		if (b%i==0) 
		{
			pr[pos] = i;
			yy[pos++] = 1;
			while(b%i==0)
			{
				b=b/i;
			}
		}
	}
	if (b!=1) 
	{
		pr[pos] = b;
		yy[pos++] = 1;		
	}
	//for(int i = 0;i<pos;i++) printf("%d\n",pr[i]);
	for(int i = 1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		for(int j = 0;j<pos;j++)
		{
			if (x%pr[j]!=0&&y%pr[j]!=0) yy[j] = 0;
		}
	}
	for(int i = 0;i<pos;i++)
	{
		if (yy[i]==1)
		{
			printf("%d\n",pr[i]);
			return 0;
		}
	}
	printf("-1\n");
	return 0; 
}