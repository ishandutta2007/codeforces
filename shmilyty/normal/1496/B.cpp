#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,n,k,a[100001]; 
set<int> s;
bool check()
{
	sort(a+1,a+1+n);
	if(a[n]==n-1) 
		return 0;
	return 1;
}
void solve()
{
	n=read();
	k=read();
	int maxx=0,mex=0;
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) 
		if(a[i]-a[i-1]>1)
		{
			mex=a[i-1]+1;
			break; 
		}
	int nxt=(mex+maxx+1)/2;
	int ans=n+1;
	if(k==0)
		ans=n;
	for(int i=1;i<=n;i++) 
		if(a[i]==nxt) 
			ans=n;
	if(check()) 
		cout<<ans<<endl;
	else 
		cout<<n+k<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}