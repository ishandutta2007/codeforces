#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
int t,n,q;
string s;
void solve()
{
	int l=read(),r=read();
	for(int i=0;i<l-1;i++)
		if(s[i]==s[l-1])
		{
			puts("YES");
			return ;
		}
	for(int i=r;i<n;i++)
		if(s[i]==s[r-1])
		{
			puts("YES");
			return ;
		}
	puts("NO");
}
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		q=read();
		cin>>s;
		while(q--)
			solve();
	}
	return 0;
}