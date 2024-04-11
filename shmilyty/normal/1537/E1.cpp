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
int n,k,len;
string s,pre,ans;
signed main()
{
	n=read();
	k=read();
	cin>>s;
	for(int i=0;i<n;i++)
	{
		pre=s;
		while(pre.size()<k)
			pre+=pre;
		if(ans=="")
			ans=pre.substr(0,k);
		else
			ans=min(ans,pre.substr(0,k));
		s.pop_back();
	}
	cout<<ans;
	return 0;
}