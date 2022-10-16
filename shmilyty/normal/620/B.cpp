#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int a,b,ans,num[]={6,2,5,5,4,5,6,3,7,6};
void solve(int x)
{
	while(x)
	{
		ans+=num[x%10];
		x/=10;
	}
}
signed main()
{
	a=read();
	b=read();
	for(int i=a;i<=b;i++)
		solve(i);
	cout<<ans;
	return 0;
}