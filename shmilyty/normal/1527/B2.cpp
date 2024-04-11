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
int t,n;
string s;
bool ispa()
{
	string ss=s;
	reverse(ss.begin(),ss.end());
	if(ss==s)
		return 1;
	return 0;
}
void solve()
{
	n=read();
	cin>>s;
	int num=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			num++;
	if(num==0)
	{
		puts("DRAW");
		return ;
	}
	if(num==2&&(n&1)&&s[n/2]=='0')
	{
		puts("DRAW");
		return ;
	}
	if(!ispa())
	{
		puts("ALICE");
		return ;
	}
	if((num&1)&&num!=1)
		puts("ALICE");
	else
		puts("BOB");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}