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
int n,top,ans,f[2000001];
array<int,3> a[2000001];
array<int,2> stk[2000001]; 
array<int,2> operator-(array<int,2> x,array<int,2> y)
{
	return {x[0]-y[0],x[1]-y[1]};
}
using ll=__int128;
ll val(array<int,2> x,array<int,2> y,array<int,2> z)
{
	y=y-x;
	z=z-x;
	return y[0]*(ll)z[1]-y[1]*(ll)z[0];
}
void add(array<int,2> x)
{
	while(top>=2&&val(stk[top-2],stk[top-1],x)<=0)
		top--;
	stk[top++]=x;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),z=read();
		a[i]={x,y,z};
	}
	sort(a+1,a+1+n);
	for(int i=1,l=0;i<=n;i++)
	{
		add({f[i-1],a[i-1][0]});
		int x=a[i][0],y=a[i][1];
		l=min(l,top-1);
		while(l+1<top&&stk[l+1][0]-stk[l+1][1]*y>=stk[l][0]-stk[l][1]*y)
			l++;
		f[i]=stk[l][0]+y*(x-stk[l][1])-a[i][2];
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}