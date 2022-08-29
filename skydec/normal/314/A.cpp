#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;


LL a[200005];
LL k,tree[5][200005];
int n;


inline LL query(int d,int x)
{
	LL ret=0;
	for(int p=x;p;p-=p&(-p))
		ret+=tree[d][p];
	return ret;
}


inline void add(int d,int x,LL val)
{
	for(int p=x;p<=n;p+=p&(-p))
		tree[d][p]+=val;
}


int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		add(1,i,1ll*a[i]*(i-1));
		add(2,i,1ll);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==17)
			i=17;
		LL val1=query(1,i)-1ll*a[i]*(i-1);
		LL val2=query(2,i)-1;
		LL val=val1-1l*val2*(n-i)*a[i];
		if(val<k)
		{
			printf("%d\n",i);
			add(2,i,-1);
			add(1,i,-1ll*a[i]*(i-1));
		}else
		{
			add(1,i,-1ll*a[i]*(i-1));
			add(1,i,1ll*a[i]*val2);
		}
	}
	return 0;
}