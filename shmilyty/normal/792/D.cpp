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
int n,q,num,b[63];
string s,a;
int lb(int x)
{
	for(int i=0;i<=num;i++)
		if(x&b[i])
			return i;
	return -1;
}
signed main()
{
	n=read();
	q=read();
	b[0]=1;
	for(int i=1;i<=62;i++)
		b[i]=b[i-1]*2;
	while(b[num]-1!=n)
		num++;
	num--;
	while(q--)
	{
		int x=read();
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(a.size()&&a[a.size()-1]!='U'&&s[i]=='U')
				a.pop_back();	
			else
				a+=s[i];
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='U')
			{
				if(x!=b[num])
				{
					int l=lb(x);
					x-=b[l];
					x|=b[l+1];
				}
				continue;
			}
			if(s[i]=='L'&&x%2==0)
			{
				int l=lb(x);
				x-=b[l];
				x+=b[l-1];
			}
			if(s[i]=='R'&&x%2==0)
			{
				int l=lb(x);
				x+=b[l-1];
			}
		}
		printf("%I64d\n",x);
	}
	return 0;
}