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
int n,k,ans,q=1;
signed main()
{
	n=read();
	k=read();
	while(q<n)
	{
		ans++;
		q*=k;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
		{
			int u=i-1,v=l-1,res=0;
			while(u!=v)
			{
				u/=k;
				v/=k;
				res++;
			}
			cout<<res<<" ";
		}
	return 0;
}