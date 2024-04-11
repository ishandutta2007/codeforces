#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int T,n,a[400001],t[800001];
void build()
{
	for(int i=2*n-2;i;i--)
		t[i]=__gcd(t[i<<1],t[i<<1|1]);
//		t[i]=t[i<<1]+t[i<<1|1];
}
int query(int l,int r)
{
	int res=0;
	for(l+=2*n-1,r+=2*n-1;l<r;l>>=1,r>>=1)
	{
		if(l&1)
//			res+=t[l++];
			res=__gcd(res,t[l++]);
		if(r&1)
//			res+=t[--r];
			res=__gcd(res,t[--r]);
	}
	return res;
}
void solve()
{
	n=read();
	int g=0,flag=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		g=__gcd(g,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]/=g;
		if(a[i]!=1)
			flag=0;
	}
	if(flag)
	{
		puts("0");
		return ;
	}
	for(int i=1;i<n;i++)
		a[i+n]=a[i];
//	for(int i=1;i<=2*n-1;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	memset(t,0,sizeof(t));
	for(int i=0;i<2*n-1;i++)
		t[i+2*n-1]=a[i+1];
	build();
	int ans=0,last=1;
	for(int i=1;i<=n;i++)
	{
		while(query(i-1,last)!=1)
			last++;
//		cout<<query(i-1,last-1)<<endl;
//		cout<<i<<" "<<last<<endl;
		ans=max(ans,last-i);
	}
	cout<<ans<<endl;
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}