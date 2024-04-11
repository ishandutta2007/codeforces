#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int l=0,r=1e9,n; 
signed main()
{
	n=read();
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(mid*(mid+1)/2<n)
			l=mid+1;
		else
			r=mid-1;
	} 
	cout<<n-l*(l-1)/2<<endl;
	return 0;
}