/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=3*1e5+100,M=3*1e6+100;
int n,a[N],b[N],cnt,tr[N],ls[M],rs[M],d[M],last[M],to[M];
int tot,first[M],nxt[M*4],point[M*4],len[M*4];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void add_edge(int x,int y,int z)
{
	nxt[++tot]=first[x];
	first[x]=tot;
	point[tot]=y;
	len[tot]=z;
}
int build(int l,int r)
{
	int x=++cnt;
	if (l==r)
	{
		tr[l]=x;to[x]=l;
		if (l!=0) add_edge(x,l+b[l],0);
		return x;
	}
	int mid=(l+r)>>1;
	add_edge(x,ls[x]=build(l,mid),0);
	add_edge(x,rs[x]=build(mid+1,r),0);
	return x;
}
void add(int x,int l,int r,int ll,int rr,int v)
{
	if (ll<=l&&rr>=r)
	{
		add_edge(v,x,1);
		return;
	}
	int mid=(l+r)>>1;
	if (ll<=mid) add(ls[x],l,mid,ll,rr,v);
	if (rr>mid) add(rs[x],mid+1,r,ll,rr,v);
}
signed main()
{
	tot=-1;
	memset(first,-1,sizeof(first));
	memset(to,-1,sizeof(to));
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	cnt=n;
	int rt=build(0,n);
	for (int i=1;i<=n;i++) add(rt,0,n,i-a[i],i,i);
	deque <int> q;
	memset(d,0x3f,sizeof(d));
	d[tr[n]]=0;q.push_back(tr[n]);
	while (!q.empty())
	{
		int x=q.front();q.pop_front();
		for (int i=first[x];i!=-1;i=nxt[i])
		{
			int u=point[i];
			if (d[u]>d[x]+len[i])
			{
				last[u]=x;
				d[u]=d[x]+len[i];
				if (len[i]==0) q.push_front(u);
				else q.push_back(u);
			}
		}
	}
	if (d[tr[0]]==inf) printf("-1\n");
	else
	{
		printf("%d\n",d[tr[0]]);
		vector <int> ans;
		int x=tr[0];ans.push_back(0);
		while (x!=tr[n])
		{
			x=last[x];
			if (to[x]!=-1&&to[x]!=n) ans.push_back(to[x]);
		}
		reverse(ans.begin(),ans.end());
		for (int i:ans) printf("%d ",i);
		printf("\n");
	}
	
}