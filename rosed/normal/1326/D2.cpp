#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
	const int N=4e6+10;
	char s[N],ss[N],ch;
	int p[N],mid,l,r,ans;
	int haku,n=1,m,len;
	int l1,r1,l2,r2;
	inline void read()//
	{
		s[0]='~';s[1]='#';//"~" 
		for(ch=getchar();ch<'a'||ch>'z';ch=getchar());
		while(ch>='a'&&ch<='z'){s[++n]=ch;s[++n]='#';ch=getchar();}
	}
	inline void main()
	{
		scanf("%d\n",&haku);
		while(haku--)
		{
			r=mid=m=ans=len=0;n=1;
			l1=1,r1=0,l2=m+1,r2=m;
			read();
			for(int i=1;i<=n;++i) if(s[i]>='a'&&s[i]<='z') ss[++m]=s[i];
			for(int i=1;i<=n;++i)
			{
				if(i<r) p[i]=min(r-i,p[(mid<<1)-i]);
				else p[i]=1;
				while(s[i-p[i]]==s[i+p[i]]) ++p[i];
				if(p[i]+i>r) r=i+p[i],mid=i;//
			}
			for(int i=1;i<=n;++i) p[i]>>=1;
			int t1=1,t2=m;
			while(ss[t1]==ss[t2]&&t2-t1>0) ++len,++t1,--t2;
			ans=len*2;
			l1=1,r1=len,l2=m-len+1,r2=m;
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
			for(int i=0;i<=n;++i) p[i]=s[i]=ss[i]=0;
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
20

*/