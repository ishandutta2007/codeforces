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
	const int N=2e5+10;
	int haku; 
	int n;
	char s[N];
	int a[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			scanf("%s",s+1);
			int sum=0;
			for(int i=1;i<n;++i)
			{
				if(s[i]=='<') ++sum;
			}
			int t=1;
			for(int i=n-1;i;--i)
			{
				if(s[i]=='<')
				{
					int j=i;
					for(;j>1;--j)
					{
						if(s[j-1]!='<') break;
					}
					int pos=j;
					while(j<=i) a[j]=t++,++j;
					i=pos;
				}
			}
			for(int i=n;i;--i)
			{
				if(!a[i]) a[i]=t++;
			}
			for(int i=1;i<=n;++i) printf("%lld ",a[i]),a[i]=0;
			puts("");
			
			t=1;
			int tmp=n;
			for(int i=1;i<n;++i)
			{
				if(s[i]=='<') a[i]=t++;
			}
			for(int i=n-1;i;--i)
			{
				if(s[i]=='<'&&i==n-1) a[i+1]=tmp--;
				if(s[i]=='>')
				{
					int j=i;
					for(;j>1;--j)
					{
						if(s[j-1]!='>') break;
					}
					int pos=j;
					while(j<=i) a[j]=tmp--,++j;
					if(j==n) a[j]=tmp--;
					i=pos;
				}
			}
			for(int i=1;i<=n;++i) printf("%lld ",a[i]),a[i]=0;
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}