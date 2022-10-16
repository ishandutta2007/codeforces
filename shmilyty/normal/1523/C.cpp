#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int t,n,cnt,st[100001];
void solve()
{
	n=read()-1;
	cnt=1;
	st[1]=1;
	int x=read();
	cout<<1<<endl;
	while(n--)
	{
		int x=read();
		if(x==1)
			st[++cnt]=1;
		else
		{
			while(st[cnt]!=x-1)
				cnt--;
			st[cnt]++;
		}
		for(int i=1;i<cnt;i++)
			cout<<st[i]<<".";
		cout<<st[cnt]<<endl;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}