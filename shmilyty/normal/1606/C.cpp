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
int t,n,k,te[19],a[20];
int work(int x)
{
	int res=0,cnt=0;
	for(int i=18;i>=0;i--)
	{
		cnt=cnt*10+(x/te[i])%10;
		if(a[i])
		{
			res+=cnt;
			cnt=0;
		}
	}
	return res;
}
void solve()
{
	n=read();
	k=read()+1;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		a[i]=read();
	a[n+1]=a[n]+15;
	for(int i=2;i<=n+1;i++)
	{
		int lst=te[a[i]-a[i-1]]-1;
		if(lst<k)
		{
			k-=lst;
			continue;
		}
		cout<<k;
		for(int l=1;l<=a[i-1];l++)
			cout<<9;
		cout<<endl;
		return ;
	}
}
signed main()
{
	te[0]=1;
	for(int i=1;i<=18;i++)
		te[i]=te[i-1]*10;
	t=read();
	while(t--)
		solve();
	return 0;
}