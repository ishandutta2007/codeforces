#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int t,n,ans;
int mod=1e9+7;
void solve()
{
	n=read();
	ans=0;
	int cnt=2,now=n,nxt,tot=2;
	while(now)
	{
		int cc=cnt/__gcd(cnt,tot);
		if(cnt==2)
			cc=cnt;
		nxt=now/cc;
		(ans+=cnt*(now-nxt)%mod)%=mod;
//		cout<<cnt<<" "<<now<<" "<<nxt<<endl;
		tot=tot/__gcd(tot,cnt)*cnt;
		cnt++;
		now=nxt;
	}
//	cout<<tot<<endl;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}