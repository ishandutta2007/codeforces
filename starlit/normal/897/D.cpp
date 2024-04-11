#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 1003
using namespace std;
int n,m,i,c,x,a[N];
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	while(m--)
	{
		scanf("%d",&x);
		if(x>(c>>1))
		for(i=n;i&&a[i]>=x;i--);
		else for(i=1;i<=n&&a[i]&&a[i]<=x;i++);
		printf("%d\n",i);
		a[i]=x;
		for(i=1;i<=n;i++)
		if(!a[i])break;
		if(i>n)return 0;
		fflush(stdout);
	}
}