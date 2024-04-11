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
int t,n,k,cnt,b[60];
int calc(int x)
{
	if(x==-1)
		return 1;
	if(x>=60)
		return 1145141145141145141ll;
	return b[x];
}
void solve()
{
	n=read();
	k=read();
	cnt=1;
	if(k>calc(n-1))
	{
		puts("-1");
		return ;
	}
	while(cnt<=n)
	{
		for(int i=1;i+cnt<=n+1;i++)
		{
			int x=calc(n-cnt-i);
			if(k<=x)
			{
				for(int l=cnt+i-1;l>=cnt;l--)
					cout<<l<<" ";
				cnt+=i;
				break; 
			}
			else
				k-=x;
		}
	}
	cout<<endl;
}
signed main()
{
	t=read();
	b[0]=1;
	for(int i=1;i<60;i++)
		b[i]=b[i-1]*2;
	while(t--)
		solve();
	return 0;
}