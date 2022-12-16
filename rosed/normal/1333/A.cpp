#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=3e5+10;
	int haku;
	int n,m,sum;
	bool flag;
	bool vis[110][110];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();
			memset(vis,0,sizeof(vis));
			sum=0;
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
				{
					if(j==1)
					{
						if(!vis[i-1][1]) vis[i][1]=1,++sum;
					}
					else
					{
						if(!vis[i][j-1]) vis[i][j]=1,++sum;
					}
				}
			}
			if(sum==n*m-sum) flag=1;
				for(int i=1;i<=n;++i)
				{
					for(int j=1;j<=m;++j)
					{
						if(flag&&!vis[i][j]) vis[i][j]=1,flag=0;
						putchar(vis[i][j]?'B':'W');
					}
					puts("");
				}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}