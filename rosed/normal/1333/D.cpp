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
	const int N=3010;
	int n,m,all=-1;
	char s[N],ss[N];
	int suf[N],a[N];
	int st[N],top;
	inline void main()
	{
		n=read(),m=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;++i) ss[i]=s[i];
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<n;++j)
			{
				if(ss[j]=='R'&&ss[j+1]=='L')
				{
					ss[j]='L',ss[j+1]='R';
					++a[i];++j;
				}
			}
			suf[i]=a[i];
			if(!a[i]&&all==-1) all=i-1;
		}
		for(int i=n;i;--i) suf[i]+=suf[i+1];
		if(suf[1]<m||all>m) return(void)puts("-1");
		for(int i=1;i<=n;++i)
		{
			int sum=min(a[i],suf[i]-m+1);
			top=0;
			for(int j=1;j<n;++j)
			{
				if(s[j]=='R'&&s[j+1]=='L')
				{
					s[j]='L',s[j+1]='R';
					if(top<sum)
					{
						st[++top]=j;
						if(top==sum)
						{
							printf("%lld ",sum);
							for(int k=1;k<=top;++k) printf("%lld ",st[k]);
							puts("");
							--m;
						}
					}
					else 
					{
						printf("1 %lld\n",j);
						--m;
					}
					++j;
				}
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
6 5
RRLRLL

*/