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
int n,t,a[501];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int l=1;l<=n;l++)
		if(a[l]!=l)
		{
			for(int j=l+1;j<=n;j++)
				if(a[j]==l)
				{
					reverse(a+l,a+j+1);
					break;
				}
			break;
		}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}