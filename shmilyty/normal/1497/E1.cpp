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
int t,n,k,ans,b[200001],p[10000001];
vector<int> v;
map<int,int> a[200001];
map<int,bool> vis;
signed main()
{
	t=read();
	for(int i=2;i<=10000000;i++)
	{
		if(!p[i])
			v.push_back(i);
		for(int l=0;l<v.size()&&v[l]*i<=10000000;l++)
			p[v[l]*i]=1;
	}
	while(t--)
	{
		n=read();
		k=read(); 
		for(int i=1;i<=n;i++)
		{
			a[i].clear();
			int x=read();
			for(int l=0;v[l]*v[l]<=x;l++)
				while(x%v[l]==0)
				{
					x/=v[l];
					a[i][v[l]]^=1;
				}
			if(x!=1)
				a[i][x]^=1;
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=1;
			for(auto it:a[i])
				if(it.second)
					b[i]*=it.first;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			vis.clear();
			ans++;
			int l=i;
			for(;l<=n;l++)
				if(vis[b[l]])
					break;
				else
					vis[b[l]]=1;
			i=l-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}