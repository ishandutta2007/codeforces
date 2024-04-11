#include <stdio.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
#define int long long
int a[300005<<2],sum[300005<<2],tag[300005<<2],charm[300005<<2];
inline void pushdown(int o,int l,int r)
{
	if(l==r)
	{
		sum[o]=sum[o]*tag[o]+charm[o];
		tag[o]=1,charm[o]=0;
		return;
	}
	int lc=o<<1,rc=lc^1;
	tag[lc]*=tag[o],charm[lc]*=tag[o],charm[lc]+=charm[o];
	tag[rc]*=tag[o],charm[rc]*=tag[o],charm[rc]+=charm[o];
	tag[o]=1,charm[o]=0;
	//maintain(lc,l,l+r>>1);
	//maintain(rc,(l+r>>1)+1,r);
	//maintain(o,l,r);
}
int n;
inline void maintain(int o,int l,int r)
{
	if(l==r)
	{
		sum[o]=sum[o]*tag[o]+charm[o];
		charm[o]=0,tag[o]=1;
		return;
	}
	sum[o]=(sum[o<<1]+sum[o<<1|1])*tag[o]+charm[o]*(r-l+1);
	//pushdown(o,l,r);
}
void mul(int o,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R)
	{
		tag[o]*=x;
		charm[o]*=x;
		maintain(o,l,r);
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)mul(o<<1,l,m,L,R,x);else maintain(o<<1,l,m);
	if(m<R)mul(o<<1|1,m+1,r,L,R,x);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
}
int query(int o,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		maintain(o,l,r);
		return sum[o];
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	int ans=0;
	if(L<=m)ans+=query(o<<1,l,m,L,R);else maintain(o<<1,l,m);
	if(m<R)ans+=query(o<<1|1,m+1,r,L,R);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
	return ans;
}
void add(int o,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R)
	{
		charm[o]+=x;
		maintain(o,l,r);
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)add(o<<1,l,m,L,R,x);else maintain(o<<1,l,m);
	if(m<R)add(o<<1|1,m+1,r,L,R,x);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
}
void debug(int o,int l,int r)
{
//	printf("%d %d %d %d")
}
struct Query{
    int l,r,x;
}q[305005];
signed main()
{
	int N=read(),m=read(),n=1;
	while(n<N)n<<=1;
	for(int i=n;i<N+n;i++)sum[i]=0;
	for(int i=1;i<n+n;i++)tag[i]=1,charm[i]=0;
	for(int i=n-1;i>=1;i--)sum[i]=sum[i<<1]+sum[i<<1|1];
	for(int i=m-1;i>=0;i--)q[i].l=read(),q[i].r=read(),q[i].x=read();
    for(int i=0;i<m;i++)
    {
        int l=q[i].l,r=q[i].r,x=q[i].x;
        int V=query(1,1,n,x,x);
        mul(1,1,n,l,r,0);
        add(1,1,n,l,r,x);
        mul(1,1,n,x,x,0);
        add(1,1,n,x,x,V);
    }
    int win=q[0].x;
    for(int i=1;i<=N;i++)
    {
        if(win==i)printf("0 ");
        else printf("%lld ",query(1,1,n,i,i));
    }
}