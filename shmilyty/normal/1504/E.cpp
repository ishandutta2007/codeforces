#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int n,ans,max1,max2,a[100001],b[100001],id[100001];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=read();
		max1=max(max1,a[i]);
		max2=max(max2,b[i]);
		id[i]=i;
		ans+=b[i];
	}
	sort(id+1,id+1+n,cmp);
	int maxx=a[id[1]]+b[id[1]];
	for(int i=2;i<=n;i++)
	{
		ans+=max(a[id[i]]-maxx,0ll);
		maxx=max(maxx,a[id[i]]+b[id[i]]);
	}
	cout<<ans;
	return 0;
}