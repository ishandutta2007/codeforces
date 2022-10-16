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
int t,n,mx,mn;
array<int,3> a[100001];
void solve()
{
	n=read();
	mx=1;mn=1;
	a[1][0]=read();
	a[1][1]=read();
	a[1][2]=read();
	cout<<a[1][2]<<'\n';
	int one=1;
	for(int i=2;i<=n;i++)
	{
		int x=read(),y=read(),z=read();
		a[i]={x,y,z};
		if(x<a[mn][0])
			mn=i;
		elif(x==a[mn][0]&&z<a[mn][2])
			mn=i;
		if(y>a[mx][1]) 
			mx=i;
		elif(y==a[mx][1]&&z<a[mx][2]) 
			mx=i;
		if(x<=a[mn][0]&&y>=a[mx][1]&&(a[one][0]>a[mn][0]||a[one][1]<a[mx][1]||z<a[one][2])) 
			one=i;
		if(mx==mn) 
			cout<<a[mn][2]<<'\n';
		elif(a[mx][0]<=a[mn][0]) 
			cout<<a[mx][2]<<'\n';
		elif(a[mn][1]>=a[mx][1])
			cout<<a[mn][2]<<'\n';
		elif(a[one][0]<=a[mn][0]&&a[one][1]>=a[mx][1])
			cout<<min(a[one][2],a[mn][2]+a[mx][2])<<'\n';
		else
			cout<<a[mn][2]+a[mx][2]<<'\n';
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}