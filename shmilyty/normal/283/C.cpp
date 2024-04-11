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
int n,q,t,a[301],pre[301],nxt[301],f[100001],fa[301];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
vector<int> v;
const int mod=1e9+7;
signed main()
{
	n=read();
	q=read();
	t=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	while(q--)
	{
		int x=read(),y=read();
		if(find(x)==find(y))
		{
			puts("0");
			return 0;
		}
		fa[find(x)]=find(y);
		pre[y]=x;
		nxt[x]=y;
	}
	for(int i=1;i<=n;i++)
		if(pre[i]==0)
		{
			int num=0,tot=0,sum=0;
			for(int l=i;nxt[l];l=nxt[l])
				num++;
//			cout<<i<<" "<<num<<endl;
			for(int l=i;num>=0;l=nxt[l])
			{
				t-=num*a[l];
				sum+=a[l];
//				cout<<l<<" "<<num<<" "<<sum<<endl;
				num--;
				v.push_back(sum);
			}
		}
//	for(int i:v)
//		cout<<i<<endl;
	f[0]=1;
	if(t<0)
	{
		puts("0");
		return 0;
	}
	for(int i:v)
		for(int l=0;l+i<=t;l++)
			(f[l+i]+=f[l])%=mod;
	cout<<f[t]<<endl;
	return 0;
}
/*
4 2 17
3 1 2 5
4 2
3 4
*/