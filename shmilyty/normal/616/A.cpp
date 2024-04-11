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
string a,b; 
int c1,c2;
signed main()
{
	cin>>a>>b;
	while(a[c1]=='0'&&c1!=a.size()-1)
		c1++;
	while(b[c2]=='0'&&c2!=b.size()-1)
		c2++;
	a=a.substr(c1,a.size()-c1);
	b=b.substr(c2,b.size()-c2);
	if(a.size()>b.size())
	{
		puts(">");
		return 0;
	}
	if(a.size()<b.size())
	{
		puts("<");
		return 0;
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<b[i])
		{
			puts("<");
			return 0;
		}
		if(a[i]>b[i])
		{
			puts(">");
			return 0;
		}
	}
	puts("=");
	return 0;
}