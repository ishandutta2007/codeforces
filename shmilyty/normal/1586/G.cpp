#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int n,q,ans,lst=1,t[400002],f[200001],id[200001];
array<int,3> a[200001];
array<int,2> b[200001];
const int mod=1e9+7;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int v)
{
	for(;x;x-=lowbit(x))
		(t[x]+=v)%=mod;
}
int query(int x)
{
	int res=0;
	for(;x<=400000;x+=lowbit(x))
		(res+=t[x])%=mod;
	return res;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={y,x,0};
	}
	q=read();
	while(q--)
		a[read()][2]=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		b[i]={a[i][1],i};
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
		id[b[i][1]]=i;
	add(2*n+1,1);
	for(int i=1;i<=n;i++)
	{
		f[i]=query(id[i]);
		add(id[i],f[i]);
	}
	for(int i=n;i;i--)
	{
		add(id[i],(mod-f[i])%mod);
		if(a[i][2]&&id[i]>=lst)
		{
			(ans+=query(lst))%=mod;
			lst=id[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}