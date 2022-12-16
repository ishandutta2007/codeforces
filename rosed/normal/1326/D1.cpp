#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define fail return (void)puts("-1")
	const int N=2e6+10,mod1=998244353,base1=131,mod2=1e9+7,base2=256;
	char s[N],ss[N],ch;
	int p[N],mid,l,r,ans;
	int haku,n=1,m,len;
	int h1[N],f1[N],h2[N],f2[N],pw1[N],pw2[N];
	int l1,r1,l2,r2;
	inline void read()//
	{
		s[0]='~';s[1]='#';//"~" 
		for(ch=getchar();ch<'a'||ch>'z';ch=getchar());
		while(ch>='a'&&ch<='z'){s[++n]=ch;s[++n]='#';ch=getchar();}
	}
	inline void main()
	{
		scanf("%lld\n",&haku);
		while(haku--)
		{
			r=mid=m=ans=len=0;n=1;
			read();
			for(int i=1;i<=n;++i) if(s[i]>='a'&&s[i]<='z') ss[++m]=s[i];
			for(int i=1;i<=n;++i)
			{
				if(i<r) p[i]=min(r-i,p[(mid<<1)-i]);
				else p[i]=1;
				while(s[i-p[i]]==s[i+p[i]]) ++p[i];
				if(p[i]+i>r) r=i+p[i],mid=i;//
				p[i]>>=1;
			}
			for(int i=pw1[0]=pw2[0]=1;i<=m;++i) pw1[i]=pw1[i-1]*base1%mod1,pw2[i]=pw2[i-1]*base2%mod2;
			for(int i=1;i<=m;++i)
			{
				h1[i]=(h1[i-1]*base1+ss[i])%mod1; 
				h2[i]=(h2[i-1]*base2+ss[i])%mod2;
			}
			reverse(ss+1,ss+m+1);
			for(int i=1;i<=m;++i)
			{
				f1[i]=(f1[i-1]*base1+ss[i])%mod1;
				f2[i]=(f2[i-1]*base2+ss[i])%mod2;
			}
			l=1,r=m>>1;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(h1[mid]==f1[mid]&&h2[mid]==f2[mid]) len=mid,l=mid+1;
				else r=mid-1;
			}
			ans=len*2;
			l1=1,r1=len,l2=m-len+1,r2=m;
			reverse(ss+1,ss+m+1);
			for(int i=len+1;i<=(m+1)/2;++i)
			{
				int t=(i<<1);
				p[t]=min(p[t],i-len);
				if(p[t]==i-len)
				{
					if((len*2+(p[t]-1)*2+1)>ans)
					{
						ans=len*2+(p[t]-1)*2+1;
						l1=1,r1=len+(p[t]-1)*2+1;
						l2=m-len+1,r2=m;
					}
				}
				if((m&1)&&(i==(m+1)/2)) break;
				++t;
				p[t]=min(p[t],i-len);
				if(p[t]==i-len)
				{
					if(len*2+p[t]*2>ans)
					{
						ans=len*2+p[t]*2;
						l1=1,r1=len+p[t]*2;
						l2=m-len+1,r2=m;
					}
				}
			}
			for(int i=m/2+1;i<=m-len;++i)
			{
				int t=(i<<1);
				if((m&1)==0||(i!=(m+1)/2))
				{
					p[t]=min(p[t],m-len-i+1);
					if(p[t]==m-len-i+1)
					{
						if((len*2+(p[t]-1)*2+1)>ans)
						{
							ans=len*2+(p[t]-1)*2+1;
							l1=1,r1=len;
							l2=m-len-(p[t]-1)*2,r2=m;
						}
					}
				}
				++t;
				p[t]=min(p[t],m-len-i);
				if(p[t]==m-len-i)
				{
					if(len*2+p[t]*2>ans)
					{
						ans=len*2+p[t]*2;
						l1=1,r1=len;
						l2=m-len-p[t]*2+1,r2=m;
					}
				}
			}

			for(int i=l1;i<=r1;++i) putchar(ss[i]);
			for(int i=l2;i<=r2;++i) putchar(ss[i]);
			puts("");
			for(int i=0;i<=n;++i) p[i]=0;
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
5
abcdecba 

*/