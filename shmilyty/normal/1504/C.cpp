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
int t,n,n1,n2,n0;
string s,s1,s2;
void solve()
{
	n=read();
	cin>>s;
	n1=n2=n0=0;
	s1="";
	s2="";
	for(int i=0;i<n;i++)
		if(s[i]=='0')
			n0++;
	if(n0&1)
	{
		puts("No");
		return ;
	}
	for(int i=0;i<n;i++)
		if(s[i]=='1')
		{
			n1++;
			if(n1<=(n-n0)/2)
			{
				s1+="(";
				s2+="(";
			}
			else
			{
				s1+=")";
				s2+=")";
			}
		}
		else
		{
			n2++;
			if(n2&1)
			{
				s1+="(";
				s2+=")";
			}
			else
			{
				s1+=")";
				s2+="(";
			}
		}
	int cnt=0;
	for(int i=0;i<n;i++)	
	{
		if(s2[i]=='(')
			cnt++;
		else
			cnt--;
		if(cnt<0)	
		{
			puts("No");
			return ;
		}
	}
	puts("Yes");
	cout<<s1<<endl<<s2<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}