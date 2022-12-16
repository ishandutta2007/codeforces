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
	int n,m,tot,opt;
	char s[1010][1010];
	int a[1010][1010];
	int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
	struct node
	{
		int x,y,f;
	};
	queue<node> q;
	inline void main()
	{
		n=read(),m=read(),tot=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s[i]+1);
		}
		memset(a,-1,sizeof(a));
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				for(int k=0;k<4;++k)
				{
					int tx=i+dx[k],ty=j+dy[k];
					if(tx<1||tx>n||ty<1||ty>m) continue;
					if(s[i][j]==s[tx][ty]) a[i][j]=1;
				}
				if(a[i][j]==1) q.push((node){i,j,1});
			}
		}
		while(!q.empty())
		{
			node now=q.front();
			q.pop();
			for(int k=0;k<4;++k)
			{
				int tx=now.x+dx[k],ty=now.y+dy[k];
				if(tx<1||tx>n||ty<1||ty>m) continue;
				if(a[tx][ty]!=-1) continue;
				a[tx][ty]=now.f+1;
				q.push((node){tx,ty,a[tx][ty]});
			}
		}
		for(int x,y,k,i=1;i<=tot;++i)
		{
			x=read(),y=read(),k=read();
			if(k<a[x][y]||a[x][y]==-1)
			{
				putchar(s[x][y]);
				puts("");
				continue;
			}
			int t=(a[x][y]-k+1)&1;
			putchar(s[x][y]^t);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}