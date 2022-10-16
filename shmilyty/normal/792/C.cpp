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
string s,ss,anss;
int sum,n,lst1=-1,lst2=-1,lst11=-1,lst22=-1,ans=114514114514114514,res;
signed main()
{
	cin>>s;
	ss=s;
	int n=s.size();
	for(int i=n-1;i>=0;i--)
	{
		sum+=s[i]-'0';
		if((s[i]-'0')%3==1)
		{
			if(lst1==-1)
				lst1=i;
			else
			if(lst11==-1)
				lst11=i;
		}
		if((s[i]-'0')%3==2)
		{
			if(lst2==-1)
				lst2=i;
			else
			if(lst22==-1)
				lst22=i;
		}
	}
	if(sum%3==0)
	{
		cout<<s;
		return 0;
	}
	if(sum%3==2)
	{
		swap(lst1,lst2);
		swap(lst11,lst22);
	}
	if(lst1!=-1)
	{
		s.erase(lst1,1);
		while(s.size()>1&&s[0]=='0')
			s.erase(0,1);
		if(s.size()>anss.size())
			anss=s;
		s=ss;
	}
	if(lst22!=-1)
	{
		s.erase(lst2,1);
		s.erase(lst22,1);
		while(s.size()>1&&s[0]=='0')
			s.erase(0,1);
		if(s.size()>anss.size())
			anss=s;
		s=ss;
	}
	sum=0;
	for(int i=0;i<anss.size();i++)
		sum+=anss[i]-'0';
	if(sum%3||anss.size()==0)
		puts("-1");
	else
		cout<<anss;
	return 0;
}