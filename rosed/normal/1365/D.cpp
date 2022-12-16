#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) (i&(-i))
	inline int read()
	{
		int x=0;char f=1,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=55;
	typedef pair<int,int> p;
	int haku;
	int n,m;
	char s[N][N];
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	bool flag,haveg,haveb,vis[N][N];
	queue<p> q;
	inline void bfs(int n,int m)
	{
		q.push(p(n,m));vis[n][m]=1;
		while(!q.empty())
		{
			p now=q.front();
			q.pop();
			for(int i=0;i<4;++i)
			{
				int tx=now.first+dx[i],ty=now.second+dy[i];
				if(tx<1||ty<1||tx>n||ty>m||vis[tx][ty]) continue;
				if(s[tx][ty]=='#') continue;
				vis[tx][ty]=1;
				q.push(p(tx,ty));
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(s[i][j]=='G'&&!vis[i][j]) flag=1;
			}
		}
	}
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();flag=haveg=haveb=0;
			for(int i=1;i<=n;++i)
			{
				scanf("%s",s[i]+1);
			}
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
				{
					vis[i][j]=0;
					haveg|=(s[i][j]=='G');
					haveb|=(s[i][j]=='B');
					if(s[i][j]=='B')
					{
						for(int k=0;k<4;++k)
						{
							int tx=i+dx[k],ty=j+dy[k];
							if(tx<1||ty<1||tx>n||ty>m) continue;
							if(s[tx][ty]=='G') flag=1;
							if(s[tx][ty]=='.') s[tx][ty]='#';
						}
					}
				}
			}
			if(flag||s[n][m]=='B')
			{
				puts("No");
				continue;
			}
			if(!haveg)
			{
				puts("Yes");
				continue;
			}
			if(s[n][m]=='#')
			{
				puts("No");
				continue;
			}
			bfs(n,m);
			puts(flag?"No":"Yes");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
6
5 5
.....
..#..
G.B#.
..#..
.....

*/