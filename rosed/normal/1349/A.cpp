#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,inf=2e9,mod=998244353; 
	int n,m,ret=1;
	int a[N]; 
	int prime[N],id[N],num;
	bool vis[N];
	inline void oula(const int n=2e5)
	{
		vis[0]=vis[1]=1;
		for(int i=2;i<=n;++i)
		{
			if(!vis[i]) prime[++num]=i,id[i]=num;
			for(int j=1;j<=num;++j)
			{
				if(prime[j]*i>n) break;
				vis[i*prime[j]]=1;
				if(i%prime[j]==0) break;
			}
		}
	}
	priority_queue<int,vector<int>,greater<int> > q[N];
	inline void fenjie(int x)
	{
		for(int i=2;i*i<=x;++i)
		{
			if(x%i==0)
			{
				int sum=0;
				while(x%i==0) x/=i,++sum;
				q[i].push(sum);
			}
		}
		if(x^1) q[x].push(1);
	}
	inline void main()
	{
		n=read();oula();
		for(int x,i=1;i<=n;++i)
		{
			x=read();
			fenjie(x);
		}
		for(int i=1;i<=num;++i)
		{
			int x=prime[i];
			if(q[x].size()==n) q[x].pop();
			if(q[x].size()==n-1)
			{
				int y=q[x].top();
				while(y--) ret*=x;
			}
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}