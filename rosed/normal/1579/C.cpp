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
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=1e5+10;
	int T,n,m,k; 
	char s[50][50];
	bool vis[50][50];
	int tot;
	inline int check(int x,int y)
	{
		int len=-1;
		int a=x,b=y,c=x,d=y;
		while(s[a][b]=='*'&&s[c][d]=='*')
		{
			--a,--b,--c,++d;
			++len;
			if(a<1||b<1||c<1||d>m) break;
		}
		return len;
	}
	inline void paint(int x,int y)
	{
		int a=x,b=y,c=x,d=y;
		while(s[a][b]=='*'&&s[c][d]=='*')
		{
			vis[a][b]=vis[c][d]=1;
			--a,--b,--c,++d;
			if(a<1||b<1||c<1||d>m) break;
		}
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read(),k=read();
			bool flag=0;
			for(int i=1;i<=n;++i) cin>>(s[i]+1);
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
				{
					if(s[i][j]=='.') continue;
					if(s[i][j]=='*')
					{
						int x=check(i,j);
					//	cout<<i<<' '<<j<<' '<<x<<"!!"<<endl; 
						if(x>=k) paint(i,j);
					}
				}
			}
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
				{
					if(vis[i][j]==0&&s[i][j]=='*') flag=1;
				} 
			}
			puts(flag?"NO":"YES");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}	
/*
1
4 9 2
*.*.*...*
.*.*...*.
..*.*.*..
.....*...

*/