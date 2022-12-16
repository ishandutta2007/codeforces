#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1) 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	int n,len,ret;
	char s[110][110];
	bool g[110];
	int f[110];
	int x[110],y[110],num,id;
	inline void main()
	{
		n=read(),len=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s[i]+1);
			for(int t=len,j=1;j<=len;++j,--t)
			{
				if(s[i][j]!=s[i][t]) break;
				if(j==len) g[i]=2;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(f[i]) continue;
 			bool flag=0;
			for(int j=i+1;j<=n&&!flag;++j)
			{
				if(f[j]) continue;
				for(int k=1,t=len;k<=len;++k,--t)
				{
					if(s[i][k]!=s[j][t]) break;
					if(k==len)
					{
						f[i]=j;
						f[j]=i;
						flag=1;
						ret+=2*len;
						x[++num]=i;
						y[num]=j;
					}
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(g[i]&&!f[i])
			{
				ret+=len;
				id=i;
				break;
			} 
		}
		printf("%lld\n",ret);
		for(int i=1;i<=num;++i)
		{
			printf("%s",s[x[i]]+1);
		}
		printf("%s",s[id]+1);
		for(int i=num;i;--i)
		{
			printf("%s",s[y[i]]+1);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}