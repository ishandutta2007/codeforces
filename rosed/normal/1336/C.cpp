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
	const int N=4e5+10,p=998244353;
	int n,m,ret;
	char s[N],t[N]; 
	int f[3010][3010];
	inline void main()
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		for(int i=0;i<=n+1;++i) f[0][i]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(s[i]==t[j]||j>m) f[i][j]=(f[i][j]+f[i-1][j+1])%p;
				if(s[i]==t[j+i-1]||j+i-1>m) f[i][j]=(f[i][j]+f[i-1][j])%p;
				if(j==1&&i>=m) ret=(ret+f[i][j])%p;
			}
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	//freopen("haha.in","r",stdin);
	red::main();
	return 0;
}