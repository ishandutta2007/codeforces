#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,sum,ans;
	int c[1010][1010];
	int f[1010][1010];
	bool vis[1010][1010];
	struct node
	{
		int x,y,f;
		inline bool operator < (const node &t) const
		{
			return f>t.f;
		}
	};
	priority_queue<node> q;
	inline int pre(int x)
	{
		if(x==1) return 2*n;
		return x-1;
	}
	inline int nxt(int x)
	{
		if(x==2*n) return 1;
		return x+1;
	}
	inline void spfa()
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				q.push((node){i,j,0});
				f[i][j]=0;
			}
		}
		while(!q.empty())
		{
			node now=q.top();
			q.pop();
			if(vis[now.x][now.y]) continue;
			int x=now.x,y=now.y;
			vis[x][y]=1;
			if(x>n&&y>n) continue;
			int prex=pre(now.x);
			int prey=pre(now.y);
			int nxtx=nxt(now.x);
			int nxty=nxt(now.y);
			if(f[prex][y]>f[x][y]+c[prex][y])
			{
				f[prex][y]=f[x][y]+c[prex][y];
				q.push((node){prex,y,f[prex][y]});
			}
			if(f[nxtx][y]>f[x][y]+c[nxtx][y])
			{
				f[nxtx][y]=f[x][y]+c[nxtx][y];
				q.push((node){nxtx,y,f[nxtx][y]});
			}
			if(f[x][prey]>f[x][y]+c[x][prey])
			{
				f[x][prey]=f[x][y]+c[x][prey];
				q.push((node){x,prey,f[x][prey]});
			}
			if(f[x][nxty]>f[x][y]+c[x][nxty])
			{
				f[x][nxty]=f[x][y]+c[x][nxty];
				q.push((node){x,nxty,f[x][nxty]});
			}
		}
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();sum=0;ans=1e18;
			for(int i=1;i<=2*n;++i)
			{
				for(int j=1;j<=2*n;++j)
				{
					c[i][j]=read();
					if(i>n&&j>n) sum+=c[i][j],c[i][j]=0;
					vis[i][j]=0;
					f[i][j]=1e18;
				}
			}
			spfa();
			ans=min(min(f[n+1][n+1],f[n+1][2*n]),min(f[2*n][n+1],f[2*n][2*n]));
			printf("%lld\n",sum+ans);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
4
1
0 8
1 99
2
0 0 8 92
0 0 56 1
4 95 12 12
12 6 23 1
2
0 0 4 2
0 0 2 4
5 1 1 3
3 1 1 5
4
0 0 0 0 0 0 0 2
0 0 0 0 0 0 2 0
0 0 0 0 0 2 0 0
0 0 0 0 2 0 0 0
1 5 12 6 1 5 2 6
1 2 3 2 6 3 6 1 
1 5 2 2 6 3 1 3
1 2 6 3 4 6 5 6

*/