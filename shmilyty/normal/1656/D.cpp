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
int t,n;
bool ok(int x)
{
    if(x<=1||x>2e9)
		return 0;
    return n>=x*(x+1)/2;
}
void solve()
{
	n=read();
	if(n&1)
	{
		puts("2");
		return ;
	}
	int num=2;
	int k=n;
	while(k%2==0)
	{
		k/=2;
		num<<=1;
	}
	if(ok(num))
		cout<<num<<'\n';
	elif(ok(k))
		cout<<k<<'\n';
	else
		puts("-1");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}