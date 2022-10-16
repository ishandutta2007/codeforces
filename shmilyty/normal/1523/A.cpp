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
int t,n,k,lef[10001],rig[10001];
string s,ss;
void solve()
{
	n=read();
	k=read();
	cin>>s;
	ss=s;
	lef[0]=114514114514114514;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='1')
			lef[i]=0;
		else
			lef[i]=lef[i-1]+1;
	rig[n+1]=114514114514114514;
	for(int i=n;i>=1;i--)
		if(s[i-1]=='1')
			rig[i]=0;
		else
			rig[i]=rig[i+1]+1;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='0')
		{
			if(lef[i]>k&&rig[i]>k)
				continue;
			if(lef[i]>k||rig[i]>k)
			{
				s[i-1]='1';
				continue;
			}
			if(rig[i]==lef[i])
				continue;
			s[i-1]='1';
		}
	cout<<s<<endl;
} 
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}