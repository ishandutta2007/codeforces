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
const int N=2*1e5+100;
int T,n,s,t,p[N],L[N],R[N],d[N],vi[N];
queue <int> q,EM;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct dsu
{
	vector <int> fa;
	void init(int n)
	{
		fa.resize(n);
		for (int i=0;i<n;i++) fa[i]=i;
	}
	int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
	void merge(int a,int b)
	{
		a=find(a);b=find(b);
		if (a==b) return;
		fa[a]=b;
	}
};
bool cmp(int a,int b){return L[a]<L[b];}
bool cmp1(int a,int b){return R[a]>R[b];}
namespace seg
{
	vector <int> A[N*4],B[N*4];
	dsu TA[N*4],TB[N*4];
	void build(int x,int l,int r)
	{
		A[x].resize(r-l+1);B[x].resize(r-l+1);
		for (int i=l;i<=r;i++) A[x][i-l]=i,B[x][i-l]=i;
		sort(A[x].begin(),A[x].end(),cmp);
		sort(B[x].begin(),B[x].end(),cmp1);
		TA[x].init(r-l+2);TB[x].init(r-l+2);
		if (l==r) return;
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
	}
	void ask1(int x,int l,int r,int ll,int rr,int v,int dis)
	{
		if (ll<=l&&rr>=r)
		{
			int pos=TA[x].find(0);
			while (pos<r-l+1)
			{
				int id=A[x][pos];
				if (L[id]>v) break;
				if (!vi[id]) q.push(id),d[id]=dis;
				vi[id]=1;
				TA[x].merge(pos,pos+1);
				pos=TA[x].find(pos+1);
			}
			return;
		}
		int mid=(l+r)>>1;
		if (ll<=mid) ask1(ls,l,mid,ll,rr,v,dis);
		if (rr>mid) ask1(rs,mid+1,r,ll,rr,v,dis);
	}
	void ask2(int x,int l,int r,int ll,int rr,int v,int dis)
	{
		if (ll<=l&&rr>=r)
		{
			int pos=TB[x].find(0);
			while (pos<r-l+1)
			{
				int id=B[x][pos];
				if (R[id]<v) break;
				if (!vi[id]) q.push(id),d[id]=dis;
				vi[id]=1;
				TB[x].merge(pos,pos+1);
				pos=TB[x].find(pos+1);
			}
			return;
		}
		int mid=(l+r)>>1;
		if (ll<=mid) ask2(ls,l,mid,ll,rr,v,dis);
		if (rr>mid) ask2(rs,mid+1,r,ll,rr,v,dis);
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();s=read();t=read();
		for (int i=1;i<=n;i++)
		{
			p[i]=read();
			L[i]=i-p[i];R[i]=i+p[i];
			L[i]=max(L[i],1);R[i]=min(R[i],n);
		}
		q=EM;
		for (int i=1;i<=n;i++) vi[i]=0;
		vi[s]=1;q.push(s);d[s]=0;
		seg::build(1,1,n);
		while (!q.empty())
		{
			int x=q.front();q.pop();
			if (x==t) break;
			if (x<R[x]) seg::ask1(1,1,n,x+1,R[x],x,d[x]+1);
			if (x>L[x]) seg::ask2(1,1,n,L[x],x-1,x,d[x]+1);
		}
		printf("%d\n",d[t]);
	}
}