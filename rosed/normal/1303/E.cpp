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
	const int N=410;
	int haku;
	char s[N],t[N];
	int f[N][N];
	int n,m;
	bool flag;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			scanf("%s",s+1);
			scanf("%s",t+1);
			n=strlen(s+1),m=strlen(t+1);
			flag=0;
			for(int d=1;d<=m;++d)
			{
				memset(f,-1,sizeof(f));
				f[0][0]=0;
				for(int i=1;i<=n;++i)
				{
					for(int j=0;j<=d;++j)
					{
						f[i][j]=f[i-1][j];
						if(j&&s[i]==t[j]) f[i][j]=max(f[i][j],f[i-1][j-1]);
						if(~f[i-1][j]&&f[i][j]<m-d&&s[i]==t[d+f[i-1][j]+1])  f[i][j]=max(f[i][j],f[i-1][j]+1);
					}
				}
				if(f[n][d]==m-d)
				{
					flag=1;
					break;
				}
			}
			puts(flag?"YES":"NO");
		}
	}
}
signed main()
{

	red::main();
	return 0;
}