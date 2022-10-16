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
int t,a,b,ans;
void solve()
{
	a=read();
	b=read();
	ans=b-a;
	for(int i=a;i<=b;i++)
	{
		int cnt=INF,tot=i;
		for(int l=20;~l;l--)
			if(!((tot>>l)&1))
			{
				if(tot+(1<<l)>=b)
					cnt=min(cnt,tot+(1<<l));
				else
					tot+=(1<<l);
			}
		ans=min(ans,i-a+cnt-b+(i!=b));	
	}
	cout<<ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}