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
string s,ss;
int ans;
bool diff(char a,char b)
{
	if(a=='<'||a=='{'||a=='('||a=='[')
		if(b=='>'||b=='}'||b==')'||b==']')
			return 1;
	return 0;
}
int match(char a,char b)
{
	if(a=='<'&&b=='>')
		return 0;
	if(a=='{'&&b=='}')
		return 0;
	if(a=='['&&b==']')
		return 0;
	if(a=='('&&b==')')
		return 0;
	return 1;
}
signed main()
{
	cin>>s;
	for(char a:s)
	{
		if(ss.size()&&diff(ss.back(),a))
		{
			ans+=match(ss.back(),a);
			ss.pop_back();
		}
		else
			ss+=a;
	}
	if(ss.size())
		puts("Impossible");
	else
		cout<<ans;
	return 0;
}