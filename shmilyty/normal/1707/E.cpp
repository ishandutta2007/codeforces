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
int n,q;
array<int,2> a[200001],t[200001][20];
array<int,2> query(int l,int r)
{
	array<int,2> res={INF,-INF};
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			res={min(res[0],a[l][0]),max(res[1],a[l][1])};
			l++;
		}
		if(r&1)
		{
			r--;
			res={min(res[0],a[r][0]),max(res[1],a[r][1])};
		}
	}
	return res;
}
array<int,2> query1(int l,int r,int id)
{
	array<int,2> res={INF,-INF};
	for(l+=n-1,r+=n-1;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			res={min(res[0],t[l][id][0]),max(res[1],t[l][id][1])};
			l++;
		}
		if(r&1)
		{
			r--;
			res={min(res[0],t[r][id][0]),max(res[1],t[r][id][1])};
		}
	}
	return res;
}
signed main()
{
	n=read();
	q=read();
	for(int i=0;i<n;i++)
	{
		int x=read()-1;
		a[i+n]={x,x};
	}
	for(int i=n-1;i>0;i--)
		a[i]={min(a[i<<1][0],a[i<<1|1][0]),max(a[i<<1][1],a[i<<1|1][1])};
	for(int i=1;i<n;i++)
	{
		array<int,2> x={i-1,i};
		t[n-2+i][0]=query(x[0],x[1]+1);
		// cout<<t[n-2+i][0][0]<<" "<<t[n-2+i][0][1]<<'\n';
	}
	for(int i=n-2;i>0;i--)
		t[i][0]={min(t[i<<1][0][0],t[i<<1|1][0][0]),max(t[i<<1][0][1],t[i<<1|1][0][1])};
	// auto x=query1(0,3,0);
	// cout<<x[0]<<" "<<x[1]<<'\n';
	// return 0;
	for(int i=1;i<20;i++)
	{
		for(int l=1;l<n;l++)
			t[n-2+l][i]=query1(t[n-2+l][i-1][0],t[n-2+l][i-1][1],i-1);
		for(int l=n-2;l>0;l--)
			t[l][i]={min(t[l<<1][i][0],t[l<<1|1][i][0]),max(t[l<<1][i][1],t[l<<1|1][i][1])};
	}
	while(q--)
	{
		int l=read()-1,r=read()-1;
		if((!l)&&r==n-1)
		{
			puts("0");
			continue;
		}
		if(l==r)
		{
			puts("-1");
			continue;
		}
		int ans=0;
		for(int i=19;~i;i--)
		{
			// cout<<l<<" "<<r<<" "<<i<<'\n';
			auto x=query1(l,r,i);
			if(x[0]||x[1]!=n-1)
			{
				// cout<<i<<":"<<x[0]<<" "<<x[1]<<'\n';
				ans|=(1<<i);
				l=x[0];
				r=x[1];
			}
		}
		auto x=query1(l,r,0);
		if(x[0]||x[1]!=n-1)
			puts("-1");
		else
			cout<<ans+1<<'\n';
	}
	return 0;
}