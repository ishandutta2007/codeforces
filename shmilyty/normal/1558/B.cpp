#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int n,m,sum,a[4000000];
signed main()
{
	n=read();
	m=read();
	a[n]=1;
	for(int i=n-1;i;i--)
	{
		int f=a[i+1];
		for(int l=2;l*i<=n;l++)
			f=(f-a[min(n,(i+1)*l-1)+1]+a[i*l]+m)%m;
		a[i]=(a[i+1]+f)%m;
		if(i==1)
			cout<<f<<endl;
	}
	return 0;
}