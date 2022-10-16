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
int T,l,r;
int calc(int x)
{
	if(!x)
		return 0;
	int a=sqrt(x);
	// assert(a*a<=x);
	while((a+1)*(a+1)<=x)
		a++;
	while(a*a>x)
		a--;
	int res=(a-1)*3;
	if(a*a<=x)
		res++;
	if(a*a+a<=x)
		res++;
	if(a*a+a+a<=x)
		res++;
	return res;
}
signed main()
{
	T=read();
	while(T--)
	{
		l=read(),r=read();
		cout<<calc(r)-calc(l-1)<<'\n';
	}
	return 0;
}