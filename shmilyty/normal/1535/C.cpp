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
int t,ans,r,last,val;
string s;
void solve()
{
	cin>>s;
	r=0;
	ans=0;
	last=-1;
	val=-1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='?')
		{
			int v=s[i]-'0';
			if(last!=-1)
				if((i-last)%2!=(val^v))
					r=last+1;
			last=i;
			val=v;
		}
		ans+=i-r+1;
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}