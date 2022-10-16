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
int q,k,n;
int check(int x)
{
	int res=0;
	for(int i=1,l=9;x>0;i++,l*=10)
	{
		int y=x-l+1;
		if(y<0)
			res+=i*(x+1)*x/2;
		else
			res+=i*(x+y)*l/2;
		x=y-1;
	}
	return res;
}
void solve()
{
	n=read();
	int l=0,r=1000000000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)<n)
			l=mid+1;
		else
			r=mid-1;
	}
	l--;
	n-=check(l);
	for(int i=1,l=9,j=1;n;i++,l*=10,j*=10)
	{
		if(n<=l*i)
		{
			int cnt=j+n/i;
			int c1=n%i;
			if(c1==0)
				cout<<(cnt-1)%10<<'\n';
			else
			{
				c1=i-c1;
				while(c1--)
					cnt/=10;
				cout<<cnt%10<<'\n';
			}
			return ;
		}
		n-=l*i;
	}
}
signed main()
{
	q=read();
	while(q--)
		solve();
	return 0;
}