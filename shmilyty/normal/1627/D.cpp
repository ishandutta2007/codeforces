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
int n,ans,a[1000001],ok[1000001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		ok[a[i]]=1;
	}
	for(int i=5e5;i;i--)
		if(!ok[i])
		{
			int cnt=0;
			for(int l=i;l<=1e6;l+=i)
				if(ok[l])
					cnt=__gcd(cnt,l);
			if(cnt==i)
				ans++;
		}
	cout<<ans;
	return 0;
}