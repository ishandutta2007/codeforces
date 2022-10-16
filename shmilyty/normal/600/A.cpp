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
vector<string> a,b;
string s,v;
signed main()
{
	cin>>s;
	s+=",";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==','||s[i]==';')
		{
			if(v.size()==0)
			{
				b.push_back("");
				continue;
			}
			bool flag=1;
			if(v[0]=='0'&&v.size()!=1)
				flag=0;
			for(int l=0;l<v.size();l++)
				if(!isdigit(v[l]))
				{
					flag=0;
					break;
				}
			if(flag)
				a.push_back(v);
			else
				b.push_back(v);
			v="";
		}
		else
			v+=s[i];
	}
	if(a.size()==0)
		puts("-");
	else
	{
		cout<<'"';
		for(int i=0;i<a.size();i++)
			cout<<a[i]<<(i!=a.size()-1?",":"\"");
		cout<<endl;
	}
	if(b.size()==0)
		puts("-");
	else
	{
		cout<<'"';
		for(int i=0;i<b.size();i++)
			cout<<b[i]<<(i!=b.size()-1?",":"\"");
	}
	return 0;
}