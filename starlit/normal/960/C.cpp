#include<bits/stdc++.h>
#define N 10004
using namespace std;
int x,d,n,tot,dig;
long long a[N],now=1;
int main()
{
    scanf("%d%d",&x,&d);
    while(x)
	{
		if(x&1)
		{
			for(int i=0;i<dig;i++)
			a[tot++]=now;
			now+=d,n++;
		}
		x>>=1,dig++;
	}
	for(int i=0;i<n;i++)
	a[tot++]=now,now+=d;
	printf("%d\n",tot);
	for(int i=0;i<tot;i++)
	printf("%lld ",a[i]);
}