#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,l,r,Ql,Qr,i,j,k,ans,now,tmp;
int w[100005];

int main()
{
	scanf("%d%d%d%d%d",&n,&l,&r,&Ql,&Qr);
	for(i=1;i<=n;++i)scanf("%d",&w[i]);
	for(i=1;i<=n;++i)now+=w[i]*r;
	ans=now+Qr*(n-1);
	for(i=1;i<=n;++i)
	{
		now-=w[i]*r;
		now+=w[i]*l;
		if(i<=n/2)tmp=now+max(n-i-i-1,0)*Qr;
		else tmp=now+max(i+i-n-1,0)*Ql;
		if(tmp<ans)ans=tmp;
	}
	printf("%d\n",ans);
}