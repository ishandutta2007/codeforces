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
int t,flag,last;
string s;
void solve()
{
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		flag=1,last=-2;
		for(int l=0;l<i;l++)
			if(s[l]=='1')
			{
				if(last+1==l)
				{
					flag=0;
					break;
				}
				last=l;
			}
		if(!flag)
			break; 
		for(int l=i;l<s.size();l++)
			if(s[l]=='0')
			{
				if(last+1==l)
				{
					flag=0;
					break;
				}
				last=l;
			}
		if(flag)
		{
			puts("Yes");
			return ;
		}
	}
	puts("No");
	return ;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}