#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,A,B,M,i,j,k,aim,key,ll,rr,L,R,S;
int a[100005],sum[100005];
long long ans[100005],Sum[100005],Ans;

struct Seg
{
	int l,r,Min;
}t[5000005];
int root,tot;

void Q(int p,int l,int r)
{
	if(!p)return;
	if(l>=ll&&r<=rr)
	{
		if(t[p].Min<key)key=t[p].Min;
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)Q(t[p].l,l,mid);
	else if(ll>mid)Q(t[p].r,mid+1,r);
		else Q(t[p].l,l,mid),Q(t[p].r,mid+1,r);
}

void C(int &p,int l,int r)
{
	if(!p)t[p=++tot].Min=key;
	if(key<t[p].Min)t[p].Min=key;
	if(l==r)return;
	int mid=l+r>>1;
	if(aim<=mid)C(t[p].l,l,mid);
	else C(t[p].r,mid+1,r);
}

int main()
{
	scanf("%d%d%d",&n,&A,&B);M=A+B;
	for(i=1;i<=n+1;++i)scanf("%d",&a[i]);
	for(i=1;i<=n+1;++i)sum[i]=(sum[i-1]+a[i])%M;
	for(i=1;i<=n+1;++i)Sum[i]=Sum[i-1]+a[i];
	for(i=n;i>=1;--i)
	{
		key=n+1;
		L=sum[i]+A;
		R=sum[i]+M-1;
		while(L>=M)L-=M,R-=M;
		if(R>=M)
		{
			ll=L+1;rr=M;
			Q(root,1,M);
			ll=1;rr=R-M+1;
			Q(root,1,M);
		}
		else
		{
			ll=L+1;rr=R+1;
			Q(root,1,M);
		}
		ans[i]=ans[key]+Sum[key]-Sum[i];
		if(key!=n+1)ans[i]+=M-(sum[key]-sum[i]+M)%M;
		aim=sum[i]+1;key=i;
		C(root,1,M);
	}
	scanf("%d",&m);
	for(;m;--m)
	{
		scanf("%d",&S);
		Ans=S;
		S%=M;
		key=n+1;
		L=A-S;
		R=M-1-S;
		while(L<0)L+=M,R+=M;
		if(R>=M)
		{
			ll=L+1;rr=M;
			Q(root,1,M);
			ll=1;rr=R-M+1;
			Q(root,1,M);
		}
		else
		{
			ll=L+1;rr=R+1;
			Q(root,1,M);
		}
		Ans+=ans[key]+Sum[key]-Sum[0];
		if(key!=n+1)Ans+=M-(sum[key]+S)%M;
		printf("%I64d\n",Ans);
	}
}