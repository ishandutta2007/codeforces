#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
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
int t,n,a[11];
void solve()
{
	n=read();
	int tot=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		tot*=3; 
	}
	for(int i=1;i<tot;i++)
	{
		int sum=0,cnt=i;
		for(int l=1;l<=n;l++)
		{
			if(cnt%3==1)
				sum+=a[l];
			if(cnt%3==2)
				sum-=a[l];
			cnt/=3;
		}
		if(sum==0)
		{
			puts("YES");
			return ;
		}
		
	}
	puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}