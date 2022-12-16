#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,p=998244353;
	int haku,n,ret;
	char s[10][10];
	int h[10][10],l[10][10],g[10][10];
	int d[10]={0,1,4,7,2,5,8,3,6,9};
	inline int belong(int i,int j)
	{
		return (i/3)*3+(j-1)/3+1;
	} 
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			memset(h,0,sizeof(h));
			memset(l,0,sizeof(l));
			memset(g,0,sizeof(g));
			for(int i=1;i<=9;++i)
			{
				scanf("%s",s[i]+1);
				for(int j=1;j<=9;++j)
				{
					int c=s[i][j]-'0';
					h[i][c]=l[j][c]=g[belong(i,j)][c]=1;
				}
			}
			for(int i=1;i<=9;++i)
			{
				int j=d[i];
				int t=1,x=s[i][j]-'0';
				while((t==x||!h[i][t]||!l[j][t]||!g[belong(i,j)][t])&&t<9) ++t;
				--h[i][x],--l[j][x],--g[belong(i,j)][x];
				++h[i][t],++l[j][t],++g[belong(i,j)][t];
				s[i][j]=t+'0';
			}
			for(int i=1;i<=9;++i) printf("%s\n",s[i]+1);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}