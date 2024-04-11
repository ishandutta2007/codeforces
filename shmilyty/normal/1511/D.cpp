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
int n,k,cnt;
string s[10001];
signed main()
{
	n=read();
	k=read();
	for(int i=0;i<k;i++)
	{
		for(int l=0;l<i;l++)
		{
			s[++cnt]='a'+l;
			s[++cnt]='a'+i;
		}
		s[++cnt]='a'+i;
	}
	for(int i=1;i<=n;i++)
		cout<<s[(i-1)%cnt+1];
	return 0;
}