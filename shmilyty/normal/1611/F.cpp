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
int t,n,k,ans,L,a[200001],f[400001];
int query(int l,int r)
{
	l--;
	int res=INF;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
			res=min(res,f[l++]);
		if(r&1)
			res=min(res,f[--r]);
	}
	return res;
}
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read()+a[i-1];
	for(int i=n;i<2*n;i++)
		f[i]=a[i-n+1];
	for(int i=n-1;i;i--)
		f[i]=min(f[i<<1],f[i<<1|1]);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]-a[i-1]+k<0)
			continue;
		int l=1,r=n-i+1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
//			cout<<i<<" "<<i+mid-1<<" "<<query(i,i+mid-1)<<endl; 
			if(query(i,i+mid-1)-a[i-1]+k<0)
				r=mid-1;
			else
				l=mid+1;
		}
		l--;
		if(l>ans)
		{
			ans=l;
			L=i;
		}
	}
	if(ans==0)
		puts("-1");
	else
		cout<<L<<" "<<L+ans-1<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}