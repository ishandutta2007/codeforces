#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
const int N=400001;
vector<int> v[N<<2];
int n,m,top,cnt,fa[N],len[N],ans[N],vis[N<<1],mp[N][2];
array<int,2> st[N<<1],e[N<<2],qry[N];
array<int,4> a[N];
int find(int x)
{
	return fa[x]==x?x:find(fa[x]);
}
void add(int x,int y)
{
	x=find(x);
	y=find(y);
	if(len[x]<len[y])
		swap(x,y);
	if(x!=y)
	{
		st[++top]={x,len[x]};
		st[++top]={y,len[y]};
		fa[y]=x;
		len[x]+=len[y];
	}
}
void del()
{
	fa[st[top][0]]=st[top][0];
	len[st[top][0]]=st[top][1];
	top--;
}
void modify(int x,int l,int r,int ll,int rr,int k)
{
	if(ll<=l&&r<=rr)
	{
		v[x].push_back(k);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)
		modify(x<<1,l,mid,ll,rr,k);
	if(mid<rr)
		modify(x<<1|1,mid+1,r,ll,rr,k);
}
void query(int x,int l,int r)
{
	int old=top;
	for(int i:v[x])
		if(vis[i])
			add(e[i][0],e[i][1]);
	if(l==r)
	{
		if(!qry[l][0])
		{
			ans[l]=ans[l-1];
			vis[mp[l][ans[l]]]^=1;
		}
		elif(find((ans[l-1]+qry[l][0]-1)%n+1)==find((ans[l-1]+qry[l][1]-1)%n+1))
			ans[l]=1;
		else
			ans[l]=0;
		while(top>old)
			del();
		return ;
	}
	int mid=(l+r)>>1;
	query(x<<1,l,mid);
	query(x<<1|1,mid+1,r);
	while(top>old)
		del();
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		len[i]=1;
	for(int i=1;i<=m;i++)
	{
		int opt=read(),x=read(),y=read();
		if(opt&1)
		{
			if(x>y)
				swap(x,y);
			a[++cnt]={x,y,i,0};
			x=x%n+1;
			y=y%n+1;
			if(x>y)
				swap(x,y);
			a[++cnt]={x,y,i,1};
		}
		else
			qry[i]={x,y};
	}
	sort(a+1,a+1+cnt);
	int c=1;
	e[1]={a[1][0],a[1][1]};
	mp[a[1][2]][a[1][3]]=1;
	for(int i=2;i<=cnt;i++)
	{
		int x=m;
		if(a[i][0]==a[i-1][0]&&a[i][1]==a[i-1][1])
			x=a[i][2];
		if(a[i-1][2]<x)
			modify(1,1,m,a[i-1][2]+1,x,c);
		if(a[i][0]!=a[i-1][0]||a[i][1]!=a[i-1][1])
			e[++c]={a[i][0],a[i][1]};
		mp[a[i][2]][a[i][3]]=c;
	}
	if(a[cnt][2]<m)
		modify(1,1,m,a[cnt][2]+1,m,c);
	// puts("ok");
	query(1,1,m);
	for(int i=1;i<=m;i++)
		if(qry[i][0])
			cout<<ans[i];
	return 0;//
}