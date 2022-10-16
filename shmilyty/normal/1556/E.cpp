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
int n,q,a[100001],b[100001],t1[300001],t2[300001];
int q1(int l,int r)
{
	l--;
	int res=-INF;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
			res=max(res,t1[l++]);
		if(r&1)
			res=max(res,t1[--r]);
	}
	return res;
}
int q2(int l,int r)
{
	l--;
	int res=-INF;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
			res=max(res,t2[l++]);
		if(r&1)
			res=max(res,t2[--r]);
	}
	return res;
}
void solve()
{
	int x=read(),y=read();
	if(a[y]-a[x-1]!=b[y]-b[x-1])
	{
		puts("-1");
		return ;
	}
	int del=a[x-1]-b[x-1];
	if(q1(x,y)>del)
	{
		puts("-1");
		return ;
	}
	cout<<q2(x,y)+del<<endl;
}
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+read();
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+read();
	for(int i=n;i<2*n;i++)
	{
		t1[i]=a[i-n+1]-b[i-n+1];
		t2[i]=b[i-n+1]-a[i-n+1];
	}
	for(int i=n-1;i;i--)
	{
		t1[i]=max(t1[i<<1],t1[(i<<1)|1]);
		t2[i]=max(t2[i<<1],t2[(i<<1)|1]);
	}
	while(q--)
		solve();
	return 0;
}