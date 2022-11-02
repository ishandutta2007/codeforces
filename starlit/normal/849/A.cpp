#include<cstdio>
#include<iostream>
#include<cstring>
#define N 101
using namespace std;
int n,a[N];
bool f[N],g[N]={1};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	for(int i=1;i<=n;i++)
	if(a[i]&1)
	{
		for(int j=i;j>0;j-=2)
		if(a[j]&1)
		{
			if(g[j-1])f[i]=1;
			if(f[j-1])g[i]=1;
		}
	}
	puts(f[n]?"Yes":"No");
}