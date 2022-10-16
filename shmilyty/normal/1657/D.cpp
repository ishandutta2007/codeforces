#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int n,C,m,k,f[1000001];
array<int,2> a[300001];
signed main()
{
	n=read();
	C=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		a[i]={x,-read()*read()};
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int x=a[i][0];
		for(int l=1;l*x<=C;l++)
			f[l*x]=max(f[l*x],-l*a[i][1]);
		int l=i;
		while(l<n&&a[l+1][0]==a[i][0])
			l++;
		i=l;
	}
	for(int i=1;i<=C;i++)
		f[i]=max(f[i],f[i-1]);
	m=read();
	while(m--)
	{
		int x=read()*read();
		int l=1,r=C;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(f[mid]<=x)
				l=mid+1;
			else
				r=mid-1;
		}
		if(l==C+1)
			cout<<"-1 ";
		else
			cout<<l<<" ";
	}
	return 0;
}