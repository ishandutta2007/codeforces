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
int n,m,a[100001],b[100001];
bool check(int x)
{
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	int cnt=1;
	for(int i=1;i<=m;i++)
	{
		int y=x-cnt;
		while(cnt<=n)
		{
			if(y>b[cnt])
			{
				y-=b[cnt];
				b[cnt++]=0;
				y--;
			}
			else
			{
				b[cnt]-=y;
				break;
			}
		}
		bool ok=1;
		for(int l=cnt;l<=n;l++)
			if(b[l])
			{
				ok=0;
				break;
			}
		if(ok)
			return 1;
	}
	return 0;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	int l=1,r=INF;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}