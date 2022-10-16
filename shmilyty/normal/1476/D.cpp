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
int t,n,r[300001],l[300001];
string s;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		cin>>s;
		l[0]=0;
		int cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			{
				if(s[i-2]!=s[i-1])
					cnt++;
				else
					cnt=1;
			}	
			l[i]=cnt;
		}
		r[n]=0;
		cnt=1;
		for(int i=n-1;i>=0;i--)
		{
			if(i!=n-1)
			{
				if(s[i+1]!=s[i])
					cnt++;
				else
					cnt=1;
			}
			r[i]=cnt;
		}
		if(s[0]=='R')
			cout<<r[0]+1<<" ";
		else
			cout<<"1 ";
		for(int i=1;i<n;i++)
		{
			int x=1;
			if(s[i-1]=='L')
				x+=l[i];
			if(s[i]=='R')
				x+=r[i];
			cout<<x<<" ";
		}
		if(s[n-1]=='L')
			cout<<l[n]+1<<endl;
		else
			cout<<"1"<<endl;
	}
	return 0;
}