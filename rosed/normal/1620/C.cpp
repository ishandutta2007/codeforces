#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int T;
	int n,m,k,sum;
	char s[N];
	int a[N];
	int st[N],b[N],top,tot;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read(),k=read();sum=0;
			cin>>(s+1);
			for(int i=1;i<=n;++i) a[i]=b[i]=0;
			tot=1;
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='a')
				{
					if(b[tot]) ++tot;
				}
				else
				{
					b[tot]+=m;
				}
			}
			a[tot]=k-1;
			for(int i=tot;i;--i)
			{
				a[i-1]+=a[i]/(b[i]+1);
				a[i]%=(b[i]+1);
			}
			//for(int i=1;i<=tot;++i) cout<<a[i]<<"!!"<<endl;
			tot=0;
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='a') putchar('a');
				else
				{
					if(s[i-1]=='a'||i==1)
					{
						++tot;
						while(a[tot]--)
						{
							putchar('b');
						}
					}

				}
			}
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}