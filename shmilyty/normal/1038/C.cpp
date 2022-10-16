#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int n,ans1,ans2,a[100001],b[100001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	sort(a+1,a+1+n,greater<int>());
	sort(b+1,b+1+n,greater<int>());
	int x1=1,x2=1;
	while(x1+x2!=2*n+2)
	{
		int q=(x1+x2)%2;
		if(x1==n+1)
		{
			if(q)
				ans2+=b[x2];
			x2++;
			continue;
		}
		if(x2==n+1)
		{
			if(!q)
				ans1+=a[x1];
			x1++;
			continue;
		}
		if(a[x1]>b[x2])
		{
			if(!q)
				ans1+=a[x1];
			x1++;
		}
		else
		{
			if(q)
				ans2+=b[x2];
			x2++;
		}
	}
	cout<<ans1-ans2<<endl;
	return 0;
}