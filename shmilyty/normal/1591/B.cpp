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
int t,n,top,mx,a[200001],stk[200001],to[200001];
void solve()
{
	n=read();
	mx=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		mx=max(mx,a[i]);	
	}
	for(int i=1;i<=n;i++)
		to[i]=-1;
	top=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&a[stk[top]]<=a[i])
			top--;
		if(top)
			to[i]=stk[top];
		stk[++top]=i;
	}
	int ans=0;
	for(int i=n;a[i]!=mx;i=to[i])
		ans++;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}