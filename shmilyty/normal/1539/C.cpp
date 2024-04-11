#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int n,k,x,a[200001];
int check(int y)
{
	vector<int> v;
	for(int i=1;i<n;i++)
		if(a[i]!=a[i+1])
			v.push_back((a[i+1]-a[i]-1)/x);
	sort(v.begin(),v.end());
	int num=0;
	for(int i=0;i+y-1<v.size();i++)
		num+=v[i];
	return (num<=k);
}
signed main()
{
	n=read();
	k=read();
	x=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}