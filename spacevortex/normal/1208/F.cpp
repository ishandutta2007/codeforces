#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define crp make_pair
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
const int N=(1<<21)+20,pn=(1<<21);
pii merge(pii a,pii b)
{
	int s[4];
	s[0]=a.fi;s[1]=a.se;s[2]=b.fi;s[3]=b.se;
	sort(s,s+4);
	return crp(s[3],s[2]);
}
int n,ans=0;
int a[N],vmx[N<<1];
pii val[N];
void FWT()
{
	int len,mid,i,j;
	for(len=2;len<=pn;len<<=1)
	{
		mid=(len>>1);
		for(i=0;i<pn;i+=len)
		{
			for(j=0;j<mid;j++)
			{
				val[i+j]=merge(val[i+j],val[i+mid+j]);
				//if(len==4&&i==4) puts("OK");
			}
		}
	}
}
void mup(int rt)
{
	vmx[rt]=max(vmx[ls],vmx[rs]);
}
void dfs(int rt,int w,int pos,int det)
{
	//printf("rt%d\n",rt);
	if(det==-1) 
	{
		ans=max(ans,w^(rt-pn));
		return ;
	}
	if(w&(1<<det)) dfs(ls,w,pos,det-1);
	else
	{
		if(vmx[rs]>pos) dfs(rs,w,pos,det-1);
		else dfs(ls,w,pos,det-1);
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		val[a[i]]=merge(val[a[i]],crp(i,0));
	}
	FWT();
	for(i=0;i<pn;i++) 
	{
		vmx[pn+i]=val[i].se;
		//printf("#%d %d %d\n",i,val[i].fi,val[i].se);
	}
	for(i=pn-1;i>=1;i--) mup(i);
	for(i=1;i<=n-2;i++)
	{
		dfs(1,a[i],i,20);
	}
	printf("%d",ans);
	return 0;
}