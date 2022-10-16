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
int n,q,a[200001],lst[200001];
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==a[i-1])
			lst[i]=lst[i-1];
		else
			lst[i]=i-1;
	}
	while(q--)
	{
		int l=read(),r=read(),x=read();
		if(a[r]!=x)
			cout<<r<<endl;
		else
			if(lst[r]>=l)
				cout<<lst[r]<<endl;
			else
				puts("-1");
	}
	return 0;
}