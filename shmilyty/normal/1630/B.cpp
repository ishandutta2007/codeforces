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
int t,n,k,a[200001],num[200001];
int check(int x)
{
	for(int i=1;i+x<=n;i++)
		if((num[i+x]-num[i-1])*2>=n+k)
			return i;
	return 0;
}
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		num[i]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++)
		num[i]+=num[i-1];
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	int L=check(l),R=L+l;
	cout<<L<<" "<<R<<endl;
	for(int i=1,j=1,tot=1,cnt=0;i<=n;i++)
	{
		if(tot==k)
		{
			cout<<i<<" "<<n<<'\n';
			return ;
		}
		if(L<=a[i]&&a[i]<=R)
			cnt++;
		else
			cnt--;
		if(cnt>0)
		{
			cout<<j<<" "<<i<<'\n';
			tot++;
			j=i+1;
			cnt=0;
		}
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}