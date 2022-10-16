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
int n,top,stk[300001],a[300001],b[300001],f[300001],pre[300001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=i-read();
	for(int i=1;i<=n;i++)
		b[i]=i+read();
	f[0]=-1;
	for(int i=n,l=i-1;i;i--)
	{
		int x=b[i];
		while(l>=a[x])
		{
			f[l]=f[i]+1;
			pre[l]=i;
			l--;
		}
	}
	cout<<f[0]<<endl;
	if(f[0]!=-1)
	{
		int cnt=0;
		while(cnt!=n)
		{
			stk[++top]=cnt;
			cnt=pre[cnt];
		}
		for(int i=top;i;i--)
			cout<<stk[i]<<" ";
	}
	return 0;
}