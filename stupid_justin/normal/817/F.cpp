//WA
#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long

using namespace std;

const int N = 12e5+10;	//1e5412e5
const int M = 1e5+10;

int n,m;
int t[M],l[M],r[M],q[M<<2];	//q[]:
int sum[N],tag[N],rev[N];
//sum[]:tag[]:rev[]: 

inline int read()	// 
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}

inline void pushup(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

inline void build(int l,int r,int rt)
{
	//0tag-1
	sum[rt]=0;
	rev[rt]=0;
	tag[rt]=-1;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

inline void pushdown(int l,int r,int rt)
{
	int mid=(l+r)>>1;
	if(tag[rt]!=-1)		//tagrev 
	{
		tag[rt<<1]=tag[rt];
		tag[rt<<1|1]=tag[rt];
		rev[rt<<1]=0;
		rev[rt<<1|1]=0;
		if(tag[rt])
		{
			sum[rt<<1]=mid-l+1;
			sum[rt<<1|1]=r-mid;
		}
		else
		{
			sum[rt<<1]=0;
			sum[rt<<1|1]=0;
		}
		tag[rt]=-1;
	}
	if(rev[rt])		//revtagtag^1,rev^1 
	{
		if(tag[rt<<1]!=-1) tag[rt<<1]^=1;
		else rev[rt<<1]^=1;
		if(tag[rt<<1|1]!=-1) tag[rt<<1|1]^=1;
		else rev[rt<<1|1]^=1;
		sum[rt<<1]=mid-l+1-sum[rt<<1];
		sum[rt<<1|1]=r-mid-sum[rt<<1|1];
		rev[rt]=0; 
	}
}

inline void update(int t,int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		if(l==r)
		{
			if(t==1) sum[rt]=1;
			else if(t==2) sum[rt]=0;
			else sum[rt]^=1;
		}
		else
		{
			if(t==1)	//1
			{
				tag[rt]=1;
				rev[rt]=0;
				sum[rt]=r-l+1;
			}
			if(t==2)	//0
			{
				tag[rt]=0;
				rev[rt]=0;
				sum[rt]=0;
			}
			if(t==3)	//
			{
				if(tag[rt]!=-1) tag[rt]^=1;
				else rev[rt]^=1;
				sum[rt]=r-l+1-sum[rt];
			}
		}
		return;
	}
	pushdown(l,r,rt);
	int mid=(l+r)>>1;
	if(L<=mid) update(t,L,R,l,mid,rt<<1);
	if(mid<R) update(t,L,R,mid+1,r,rt<<1|1);
	pushup(rt);
}

inline int query(int l,int r,int rt)
{
	if(l==r) return l;
	pushdown(l,r,rt);
	int mid=(l+r)>>1;
	//sum<0
	if(sum[rt<<1]<mid-l+1) return query(l,mid,rt<<1);
	else return query(mid+1,r,rt<<1|1);
}

signed main()
{
	m=read();
	q[++n]=1;
	for(int i=1; i<=m; i++)
	{
		t[i]=read(),l[i]=read(),r[i]=read();
		q[++n]=l[i],q[++n]=r[i],q[++n]=r[i]+1;	// 
	}
	// 
	sort(q+1,q+1+n);			//
	n=unique(q+1,q+1+n)-(q+1);	//
	build(1,n,1);
	for(int i=1; i<=m; i++)
	{
		l[i]=lower_bound(q+1,q+1+n,l[i])-q;
		r[i]=lower_bound(q+1,q+1+n,r[i])-q;
		update(t[i],l[i],r[i],1,n,1);
		printf("%lld\n",q[query(1,n,1)]);
	}
	return 0;
}