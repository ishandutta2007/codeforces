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
int n,k,ans;
array<int,2> a[500001];
bool cmp(array<int,2> x,array<int,2> y)
{
	if(max(x[0],x[1])!=max(y[0],y[1]))
		return max(x[0],x[1])<max(y[0],y[1]);
	if(min(x[0],x[1])!=min(y[0],y[1]))
		return min(x[0],x[1])<min(y[0],y[1]);
	if(x[0]>x[1]&&y[0]<y[1])
		return 1;
	return 0;
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={x,y};
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(k<=a[i][0])
		{
			ans++;
			k=max(k,a[i][1]);
		}
	cout<<ans;
	return 0;
}