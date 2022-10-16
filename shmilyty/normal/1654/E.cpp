#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
const int N=240;
int n,ans,a[100001],num[50000101];
void case1()//|d|<=N
{
	int M=25000000;
	for(int i=-N;i<=N;i++)
	{
		for(int l=1;l<=n;l++)
		{
			num[a[l]-i*(l-1)+M]++;
			ans=max(ans,num[a[l]-i*(l-1)+M]);
		}
		for(int l=1;l<=n;l++)
			num[a[l]-i*(l-1)+M]--;
	}
}
void case2()//|d|>N
{
	int M=100000;
	for(int i=1;i<=n;i++)
	{
		for(int l=i+1;l<=n&&l<=i+M/N;l++)
			if(!((a[l]-a[i])%(l-i)))
			{
				num[(a[l]-a[i])/(l-i)+M]++;
				ans=max(ans,num[(a[l]-a[i])/(l-i)+M]+1);
			}
		for(int l=i+1;l<=n&&l<=i+M/N;l++)
			if(!((a[l]-a[i])%(l-i)))
				num[(a[l]-a[i])/(l-i)+M]--;
	}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	case1();
	case2();
	cout<<n-ans;
	return 0;
}