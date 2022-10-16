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
int t,n,m,a,b;
void solve()
{
	n=read();
	a=b=0;
	while(n--)
		a=max(a,read());
	m=read();
	while(m--)
		b=max(b,read());
	if(a==b)
		cout<<"Alice\nBob\n";
	elif(a>b)
		cout<<"Alice\nAlice\n";
	else
		cout<<"Bob\nBob\n";
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}