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
int t;
string s;
void solve()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[s.size()-i-1]!='a')
		{
			puts("Yes");
			cout<<s.substr(0,i)+"a"+s.substr(i,s.size()-i)<<endl;
			return ;
		}
	puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}