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
int n,lst,t;
int ask(int x)
{
	cout<<"+ "<<x<<endl;
	return read();
}
signed main()
{
	n=read();
	int l=1,r=n-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int q=(n*2-mid-t%n)%n;
		t+=q;
		int x=ask(q);
		if(x==lst)
			r=mid-1;
		else
			l=mid+1;
		lst=x;
	}
	cout<<"! "<<l+t-1<<endl;
	return 0;
}