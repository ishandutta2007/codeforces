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
int t,n,k;
string s;
void solve()
{
	n=read();
	k=read();
	cin>>s;
	if(k*2>=n)
	{
		puts("No");
		return ;
	}
	for(int i=1;i<=k;i++)
		if(s[i-1]!=s[n-i])
		{
			puts("No");
			return ;
		}
	puts("Yes");
	return ;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}