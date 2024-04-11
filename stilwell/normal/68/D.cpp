#include <stdio.h>
#include <stdlib.h>
using namespace std;

int N,n,m,i,j,k,u,v;
int st[105],top;
int sum[5000005],val[5000005],l[5000005],r[5000005],tot;
long long ans;
double tmp;
char opt[15]; 

void Q(int p,int ll,int rr,int Max)
{
	if((!l[p]&&!r[p])||(Max>=sum[p]))
	{
		if(sum[p]>=Max)Max=sum[p];
		ans+=1ll*Max*(rr-ll+1);
		return;
	}
	int mid=ll+rr>>1,tmp;
	tmp=val[p]+sum[r[p]];
	if(Max>tmp)tmp=Max;
	Q(l[p],ll,mid,tmp);
	tmp=val[p]+sum[l[p]];
	if(Max>tmp)tmp=Max;
	Q(r[p],mid+1,rr,tmp);
}

int main()
{
	scanf("%d%d",&n,&m);
	tot=1;N=1<<n;
	for(;m;--m)
	{
		scanf("%s",opt+1);
		if(opt[1]=='a')
		{
			scanf("%d%d",&u,&v);
			for(top=0;u;u>>=1)st[++top]=u;
			u=1;
			for(i=top-1;i>=1;--i)
			{
				if(st[i]&1)
				{
					if(!r[u])r[u]=++tot;
					u=r[u];
				}
				else
				{
					if(!l[u])l[u]=++tot;
					u=l[u];
				}
				st[i]=u;
			}
			val[st[1]]+=v;
			for(i=1;i<=top;++i)sum[st[i]]+=v;
		}
		else
		{
			ans=0;
			Q(1,1,N,0);
			tmp=(double)(ans%N)/N+ans/N%10;
			if(ans/N/10)printf("%I64d",ans/N/10);
			printf("%.8lf\n",tmp);
		}
	}
}