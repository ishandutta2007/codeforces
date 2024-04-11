#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int n,m,cnt,ans,a[600001],f[1200001],t[2400001],tag[2400001];
vector<pair<int,int> > v[300001];
map<int,int> mp;
void push_up(int x)
{
	t[x]=max(t[x<<1],t[x<<1|1]); 
}
void push_down(int x)
{
	if(tag[x])
	{
		t[x<<1]=max(t[x<<1],tag[x]);
		t[x<<1|1]=max(t[x<<1|1],tag[x]);
		tag[x<<1]=max(tag[x<<1],tag[x]);
		tag[x<<1|1]=max(tag[x<<1|1],tag[x]);
		tag[x]=0;
	}
} 
void modify(int x,int l,int r,int ll,int rr,int v)
{
	if(l>=ll&&r<=rr)
	{
		t[x]=max(t[x],v);
		tag[x]=max(tag[x],v);
		return ;
	}
	push_down(x);
	int mid=(l+r)>>1;
	if(mid>=ll)
		modify(x<<1,l,mid,ll,rr,v);
	if(mid<rr)
		modify(x<<1|1,mid+1,r,ll,rr,v);
	push_up(x);
}
int query(int x,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return t[x];
	push_down(x);
	int mid=(l+r)>>1,res=0;
	if(mid>=ll)
		res=max(res,query(x<<1,l,mid,ll,rr));
	if(mid<rr)
		res=max(res,query(x<<1|1,mid+1,r,ll,rr));
	return res;
}
signed main()
{
	n=read();
	m=read();
	while(m--)
	{
		int i=read(),x=read(),y=read();
		v[i].push_back({x,y});
		mp[x];
		mp[y];
	}
	for(auto &i:mp)
		i.second=++cnt;
	for(int i=1;i<=n;i++)
		for(auto &l:v[i])
		{
			l.first=mp[l.first];
			l.second=mp[l.second]; 
		}
	for(int i=1;i<=n;i++)
	{
		for(auto l:v[i])
			f[i]=max(f[i],query(1,1,cnt,l.first,l.second));
		f[i]++;
		f[i]=min(f[i],n);
		ans=max(ans,f[i]);
		for(auto l:v[i])
			modify(1,1,cnt,l.first,l.second,f[i]);
	}
	cout<<n-ans<<endl;
	if(ans==n)
		return 0;
	int pos=0;
	for(int i=n;i;i--)
		if(f[i]==ans)
		{
			pos=i;
			break;
		}
		else
			cout<<i<<" ";
	int val=1;
	memset(t,0,sizeof(t));
	memset(tag,0,sizeof(tag));
	for(auto i:v[pos])
		modify(1,1,cnt,i.first,i.second,1);
	for(int i=pos-1;i;i--)
	{
		int res=0;
		for(auto l:v[i])
			res=max(res,query(1,1,cnt,l.first,l.second));
		if(res==val&&f[i]==ans-val)
		{
			val++;
			for(auto l:v[i])
				modify(1,1,cnt,l.first,l.second,val);
		}
		else
			cout<<i<<" ";
	}
	return 0;
}