#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,tot;
int id[70];
unsigned long long Base[70],base[70],use[70],p,x,sum;
bool ans[100005];

bool check(long long x)
{
	int i,j;long long y;
	for(i=0;i<=63;++i)base[i]=0;
	for(i=0;i<=63;++i)
	{
		y=Base[i]&x;
		for(j=63;j>=0;--j)
		if((y>>j)&1)
		{
			if(base[j])y^=base[j];
			else{base[j]=y;break;}
		}
	}
	for(i=63;i>=0;--i)
	if((x>>i)&1)
	{
		if(base[i])x^=base[i];
		else return false;
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%I64u",&x);
		p=0;sum^=x;
		for(j=63;j>=0;--j)
		if((x>>j)&1)
		{
			if(Base[j])x^=Base[j],p^=use[j];
			else
			{
				Base[j]=x;
				use[j]=p+(1ll<<tot);
				id[tot]=i;
				++tot;
				break;
			}
		}
	}
	x=0;
	for(i=63;i>=0;--i)
	if(!((sum>>i)&1))
	{
		if(check(x+(1ll<<i)))
		x+=1ll<<i;
	}
	for(i=63;i>=0;--i)
	if((sum>>i)&1)
	{
		if(check(x+(1ll<<i)))
		x+=1ll<<i;
	}
	p=0;
	for(i=63;i>=0;--i)
	if((x>>i)&1)
	{
		x^=Base[i];
		p^=use[i];
	}
	for(i=63;i>=0;--i)
	if((p>>i)&1)
	ans[id[i]]=true;
	for(i=1;i<=n;++i)if(ans[i])printf("2 ");else printf("1 ");
	printf("\n");
}