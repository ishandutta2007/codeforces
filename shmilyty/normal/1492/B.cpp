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
int t,n,ans,a[100001],f[100001];
vector<int> v;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<=n;i++)
			if(a[i]>a[f[i-1]])
				f[i]=i;
			else
				f[i]=f[i-1];
//		ans=0;
		v.clear();
		int last=n,cnt=n-1;
		while(last!=0)
		{
			for(int i=f[last];i<=last;i++)
			{
				v.push_back(a[i]);
				cnt--;
			}
			last=f[last]-1;
		}
		for(int i:v)
			cout<<i<<" ";
		cout<<endl;
//		cout<<ans<<endl;
	}
	return 0;
}