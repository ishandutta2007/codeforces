#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,l,i,j,k,u,v,ll,rr,key,L,R;
int col[100005];
int Max[18][400005],Min[18][400005],*t;
long long ans;
bool opt;

void Q(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		if(opt)
		{
			if(t[p]>key)
			key=t[p];
		}
		else
		{
			if(t[p]<key)
			key=t[p];
		}
		return;
	}
	int mid=(l+r)/2;
	if(rr<=mid)Q(p*2,l,mid);
	else if(ll>mid)Q(p*2+1,mid+1,r);
		else Q(p*2,l,mid),Q(p*2+1,mid+1,r);
}

int bit;
void change(int x,int c)
{
	int i;
	for(bit=0;bit<=17;++bit)
	{
		if(c&(1<<bit))u=1;else u=0;
		if(col[x]&(1<<bit))v=1;else v=0;
		if(u==v)continue;
		if(u)
		{
			t=Max[bit];ll=1;rr=x-1;key=0;opt=true;
			if(ll<=rr)Q(1,1,l);L=key+1;
			ans-=(long long)(x-key-1)*(x-key)/2*(1<<bit);
			t=Min[bit];ll=x+1;rr=n;key=n+1;opt=false;
			if(ll<=rr)Q(1,1,l);R=key-1;
			ans-=(long long)(key-x-1)*(key-x)/2*(1<<bit);
			ans+=(long long)(R-L+1)*(R-L+2)/2*(1<<bit);
			i=l+x-1;
			Max[bit][i]=0;
			Min[bit][i]=n+1;
			for(i/=2;i;i/=2)
			Max[bit][i]=max(Max[bit][i*2],Max[bit][i*2+1]),
			Min[bit][i]=min(Min[bit][i*2],Min[bit][i*2+1]);
		}
		else
		{
			t=Max[bit];ll=1;rr=x-1;key=0;opt=true;
			if(ll<=rr)Q(1,1,l);L=key+1;
			ans+=(long long)(x-key-1)*(x-key)/2*(1<<bit);
			t=Min[bit];ll=x+1;rr=n;key=n+1;opt=false;
			if(ll<=rr)Q(1,1,l);R=key-1;
			ans+=(long long)(key-x-1)*(key-x)/2*(1<<bit);
			ans-=(long long)(R-L+1)*(R-L+2)/2*(1<<bit);
			i=l+x-1;
			Max[bit][i]=x;
			Min[bit][i]=x;
			for(i/=2;i;i/=2)
			Max[bit][i]=max(Max[bit][i*2],Max[bit][i*2+1]),
			Min[bit][i]=min(Min[bit][i*2],Min[bit][i*2+1]);
		}
	}
	col[x]=c;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(l=1;l<n;l*=2);
	for(i=0;i<=17;++i)
	{
		for(j=1;j<=n;++j)
		Max[i][l+j-1]=Min[i][l+j-1]=j;
		for(j=l-1;j;--j)
		Max[i][j]=max(Max[i][j*2],Max[i][j*2+1]),
		Min[i][j]=min(Min[i][j*2],Min[i][j*2+1]);
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		change(i,k);
	}
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		change(u,v);
		printf("%I64d\n",ans);
	}
}