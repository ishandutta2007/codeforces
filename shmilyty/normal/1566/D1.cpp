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
int T,n,m,ans,t[301];
array<int,3> a[90001],b[90001];
bool cmp(array<int,3> x,array<int,3> y)
{
	if(x[0]==y[0])
		return x[1]>y[1];
	return x[0]<y[0];
}
bool c1(array<int,3> x,array<int,3> y)
{
	return x[1]<y[1];
}
void solve()
{
	n=read();
	m=read();
	ans=0;
	for(int i=1;i<=n*m;i++)
		a[i]={read(),i,0};
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		a[i][2]=i;
	for(int i=1;i<=n*m;i++)
		t[i]=0;
	sort(a+1,a+1+n*m,c1);
	for(int i=1;i<=n*m;i++)
	{
		int s=a[i][2];
		for(int l=1;l<=s;l++)
			ans+=t[l];
		t[s]=1;
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