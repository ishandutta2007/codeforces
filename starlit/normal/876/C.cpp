#include<cstdio>
#include<iostream>
#include<cstring>
#define N 100
using namespace std;
int n,m,d,st[N],tot;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=81&&i<n;i++)
	{
		d=n-i,m=0;
		while(d)
		m+=d%10,d/=10;
		if(m==i)
		st[tot++]=n-i;
	}
	printf("%d\n",tot);
	while(tot--)
	printf("%d ",st[tot]);
}