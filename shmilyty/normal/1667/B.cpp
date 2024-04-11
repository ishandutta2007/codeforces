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
int T,n,cnt,mx,a[500001],t[2][2000001],lst[500002];
map<int,int> mp;
void build(int x,int l,int r)
{
	mx=max(mx,x);
	if(l==r)
	{
		t[0][x]=t[1][x]=-INF;
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[0][x]=t[1][x]=-INF;
}
void modify(int x,int l,int r,int pos,int v,int id)
{
	if(l==r)
	{
		t[id][x]=max(t[id][x],v);
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)
		modify(x<<1,l,mid,pos,v,id);
	else
		modify(x<<1|1,mid+1,r,pos,v,id);
	t[id][x]=max(t[id][x<<1],t[id][x<<1|1]);
}
int query(int x,int l,int r,int L,int R,int id)
{
	if(L<=l&&r<=R)
		return t[id][x];
	int mid=(l+r)>>1,res=-INF;
	if(mid>=L)
		res=max(res,query(x<<1,l,mid,L,R,id));
	if(mid<R)
		res=max(res,query(x<<1|1,mid+1,r,L,R,id));
	return res;
}
void solve()
{
	n=read();
	mp.clear();
	mp[0];
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+read();
		mp[a[i]];
	}
	cnt=0;
	for(auto &i:mp)
		i.second=++cnt;
	// cout<<cnt<<endl;
	// cout<<mx<<endl;
	for(int i=1;i<=cnt;i++)
		lst[i]=-INF;
	build(1,1,cnt);
	// cout<<mx<<endl;
	modify(1,1,cnt,mp[0],0,0);
	modify(1,1,cnt,mp[0],0,1);
	lst[mp[0]]=0;
	for(int i=1;i<=n;i++)
	{
		int x=-INF;
		if(mp[a[i]]!=1)
			x=max(x,query(1,1,cnt,1,mp[a[i]]-1,0)+i);
		if(mp[a[i]]!=cnt)
			x=max(x,query(1,1,cnt,mp[a[i]]+1,cnt,1)-i);
		// cout<<i<<" "<<x<<endl;
		x=max(x,lst[mp[a[i]]]);
		modify(1,1,cnt,mp[a[i]],x-i,0);
		modify(1,1,cnt,mp[a[i]],x+i,1);
		if(i==n)
			cout<<x<<'\n';
		lst[mp[a[i]]]=max(lst[mp[a[i]]],x);
	}
}
signed main()
{
	// fileio("1");
	T=read();
	while(T--)
		solve();
	return 0;
}