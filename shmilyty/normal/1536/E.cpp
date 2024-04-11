#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
const int mod=1e9+7;
int t,n,m,x,y,ans;
string s;
void solve()
{
	n=read();
	m=read();
	x=y=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int l=0;l<s.size();l++)
			if(s[l]=='#')
				x++;
			else
				y++;
	} 
	ans=1;
	for(int i=1;i<=x;i++)
		(ans*=2)%=mod;
	if(y==0)
		ans--;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}