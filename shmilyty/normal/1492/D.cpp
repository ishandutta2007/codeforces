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
int a,b,k;
string s1,s2;
signed main()
{
	a=read();
	b=read();
	k=read();
	if(k==0)
	{
		while(b--)
			s1+="1";
		while(a--)
			s1+="0";
		cout<<"Yes\n"<<s1<<endl<<s1;
		return 0;	
	}
	if(a==0||b==1)
	{
		puts("No");
		return 0;
	}
	if(a+b-1<=k)
	{
		puts("No");
		return 0;
	}
	s1+="11";
	s2+="10";
	a-=1;
	b-=2;
	while(s1.size()!=k+1&&b)
	{
		s1+="1";
		s2+="1";
		b--;
	}
	while(s1.size()!=k+1&&a)
	{
		s1+="0";
		s2+="0";
		a--;
	}
	s1+="0";
	s2+="1";
	while(a--)
	{
		s1+="0";
		s2+="0";
	}
	while(b--)
	{
		s1+="1";
		s2+="1";
	}
	cout<<"Yes\n"<<s1<<endl<<s2;
	return 0;
}