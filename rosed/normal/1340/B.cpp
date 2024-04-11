#include<bits/stdc++.h>
using namespace std;
namespace red{
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
	const int N=2010,inf=1e9+7;
	int n,m,tmp;
	char s[10];
	bitset<7> a[N],num[10];
	int ans[N];
	bool vis[N][N];
	inline void dfs(int now,int sum)
	{
		if(now==n+1&&!sum)
		{
			for(int i=1;i<=n;++i) printf("%d",ans[i]);
			puts("");
			exit(0);
		}
		if(now>n||vis[now][sum]) return;
		for(int x,i=9;~i;--i)
		{
			if((a[now]|num[i])==num[i]) x=num[i].count()-a[now].count();
			else x=inf;
			if(sum-x<0) continue;
			ans[now]=i;
			dfs(now+1,sum-x);
		}
		vis[now][sum]=1;
	}
	inline void main()
	{
		n=read(),m=read();
		for(int tmp,i=1;i<=n;++i)
		{
			scanf("%s",s+1);tmp=0;
			for(int j=1;j<=7;++j)
			{
				tmp=tmp*2+s[j]-'0';
			}
			a[i]=tmp;
		}
		num[0]=119;num[1]=18,num[2]=93,num[3]=91,num[4]=58,num[5]=107,num[6]=111,num[7]=82,num[8]=127,num[9]=123;
		dfs(1,m);
		puts("-1");
	}
}
signed main()
{
	red::main();
	return 0;
}