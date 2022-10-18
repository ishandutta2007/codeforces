/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100,B=400;
int n,q,a[N],id[N],sum[N];
char s[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct node
{
	int cnt,pre,suc,ans;
	int get(){return ans+cnt;}
};
node operator +(node a,node b)
{
	a.ans+=b.ans;
	if (!a.cnt&&!b.cnt)
	{
		a.pre^=b.pre;a.suc^=b.suc;
		return a;
	}
	if (!a.cnt&&b.cnt)
	{
		a.pre^=b.pre;a.cnt=b.cnt;a.suc=b.suc;
		return a;	
	}
	if (a.cnt&&!b.cnt)
	{
		a.suc^=b.pre;
		return a;
	}
	a.suc^=b.pre;
	if (a.suc)
	{
		if (a.cnt==b.cnt)
		{
			a.ans+=a.cnt;
			a.pre^=a.suc^b.suc;
			a.suc=a.pre;a.cnt=0;
		}
		else if (a.cnt>b.cnt)
		{
			a.ans+=b.cnt;a.cnt-=b.cnt;a.suc^=b.suc;
		}
		else
		{
			a.ans+=a.cnt;a.pre^=a.suc;
			a.cnt=b.cnt-a.cnt;a.suc=b.suc;
		}
	}
	else a.cnt+=b.cnt,a.suc=b.suc;
	return a;
}
namespace seg
{
	node sh[N*4];
	void pushup(int x){sh[x]=sh[ls]+sh[rs];}
	void build(int x,int l,int r)
	{
		if (l==r)
		{
			if (a[l]) sh[x]=(node){0,1,1,0};
			else sh[x]=(node){1,0,0,0};
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(x);
	}
	node query(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r) return sh[x];
		int mid=(l+r)>>1;node ans=(node){0,0,0,0};
		if (ll<=mid) ans=ans+query(ls,l,mid,ll,rr);
		if (rr>mid) ans=ans+query(rs,mid+1,r,ll,rr);
		return ans; 
	}
}
signed main()
{
	n=read();q=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) a[i]=(s[i]=='1');
	for (int i=1;i<n;i++) a[i]^=a[i+1];
	for (int i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
	if (n>1) seg::build(1,1,n-1);
	int tmp=0;
	while (q--)
	{
		int l=read(),r=read()-1,d=(sum[r]-sum[l-1]>0);
		if (r<l)
		{
			printf("1\n");
			continue;
		}
		if (!d)
		{
			printf("%d\n",r-l+2);
			continue;
		}
		node ans=seg::query(1,1,n-1,l,r);
		printf("%d\n",ans.get()+d);
	}
}