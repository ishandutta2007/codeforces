#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=4e5+50,inf=(ll)1e18;
ll n,K,top,ans=0;
ll a[N],b[N],f[N],g[N],stk[N];
struct Segment_tree
{
	ll hmi[N],gmi[N],tag[N];
	void mup(ll rt)
	{
		hmi[rt]=min(hmi[ls],hmi[rs]);
		gmi[rt]=min(gmi[ls],gmi[rs]);
	}
	void cov(ll rt,ll w)
	{
		tag[rt]+=w;hmi[rt]+=w;
	}
	void mdown(ll rt)
	{
		if(tag[rt]) 
		{
			cov(ls,tag[rt]);
			cov(rs,tag[rt]);
			tag[rt]=0;
		}
	}
	void build(ll rt,ll l,ll r)
	{
		if(l==r)
		{
			hmi[rt]=g[l]+inf;
			gmi[rt]=g[l];
			return ;
		}
		ll mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		mup(rt);
	}
	void add(ll rt,ll l,ll r,ll x,ll y,ll w)
	{
		if(l>=x&&r<=y)
		{
			cov(rt,w);
			return ;
		}
		ll mid=(l+r)>>1;
		mdown(rt);
		if(mid>=x) add(ls,l,mid,x,y,w);
		if(mid<y) add(rs,mid+1,r,x,y,w);
		mup(rt);
	}
	ll query(ll rt,ll l,ll r,ll der,ll vmi)
	{
		if(l==r) return l;
		ll mid=(l+r)>>1;
		mdown(rt);
		//printf("S%lld %lld  %lld %lld\n",l,r,min(vmi,hmi[ls]),gmi[rs]);
		if(min(vmi,hmi[ls])>=gmi[rs]-der) return query(rs,mid+1,r,der,min(vmi,hmi[ls]));
		else return query(ls,l,mid,der,vmi);
	}
	ll query(ll rt,ll l,ll r,ll pos,ll der,ll vmi)
	{
		if(r<=pos)
		{
			if(vmi>=gmi[rt]-der) return query(rt,l,r,der,vmi);
			else return -1;
		}
		ll mid=(l+r)>>1,ret=-1;
		mdown(rt);
		if(mid<pos) ret=query(rs,mid+1,r,pos,der,min(vmi,hmi[ls]));
		if(ret==-1) ret=query(ls,l,mid,pos,der,vmi);
		return ret;
	}
}sgt;
int main()
{
	ll i,x,sl,sr,mid,pos,all,der,R;
	n=rd();K=rd();
	for(i=1;i<n;i++) b[i]=rd();
	for(i=1;i<=n;i++) a[i]=rd();
	f[1]=0;
	for(i=2;i<=n;i++) f[i]=f[i-1]+a[i-1]-b[i-1];
	g[n]=0;
	for(i=n-1;i>=1;i--) g[i]=g[i+1]+a[i+1]-b[i];
	sgt.build(1,1,n);
	top=0;
	for(i=n;i>=1;i--)
	{
		//printf("solve%lld\n",i);
		sgt.add(1,1,n,i,i,-inf);
		//puts("OK");
		while(top>0&&f[stk[top]]>=f[i])
		{
			x=stk[top];top--;
			if(top>0&&stk[top]>=3) sgt.add(1,1,n,1,stk[top]-2,f[stk[top]]-f[x]);
		}
		if(top>0&&stk[top]>=3) sgt.add(1,1,n,1,stk[top]-2,f[i]-f[stk[top]]);
		stk[++top]=i;
		if(f[i]-f[stk[1]]<=K) pos=n;
		else
		{
			sl=1;sr=top;
			while(sl<sr)
			{
				mid=(sl+sr+1)>>1;
				if(f[i]-f[stk[mid]]>K) sl=mid;
				else sr=mid-1;
			}
			pos=stk[sl];
		}
		
		all=f[i]-f[stk[1]];
		der=K-all;
		//printf("pos%lld %lld\n",pos,der);
		R=sgt.query(1,1,n,pos,der,inf);
		//printf("R%lld\n",R);
		ans=max(ans,R-i+1);
	}
	printf("%lld\n",ans);
	return 0;
}