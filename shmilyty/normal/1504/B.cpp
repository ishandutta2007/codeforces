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
string s1,s2;
void solve()
{
	n=read();
	cin>>s1>>s2;
	n--;
	while(s1[n]==s2[n]) 
		n--;
	n++;
	for(int i=0;i<n;i++)
	{
		int c1=0,c2=0;
		while(s1[i]!=s2[i]&&i!=n)
		{
			c1+=s1[i]-'0';
			c2+='1'-s1[i];
			i++;
		}
		if(c1!=c2)
		{
			puts("No");
			return ;
		}
		while(s1[i]==s2[i]&&i!=n)
		{
			c1+=s1[i]-'0';
			c2+='1'-s1[i];
			i++;
		}
		i--;
		if(c1!=c2)
		{
			puts("No");
			return ;
		}
	}
	puts("Yes");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}