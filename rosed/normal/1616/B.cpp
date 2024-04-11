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
	const int N=3e5+10,mod=998244353;
	int T,n,pos;
	char s[N];
	int pre[N],nxt[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			cin>>(s+1);pos=n;
			for(int i=1;i<=n;++i) pre[i]=nxt[i]=0;
			for(int i=1;i<=n;++i)
			{
				if(s[i]==s[i-1]) pre[i]=pre[i-1];
				else pre[i]=i-1;
			} 
			nxt[n]=0;
			for(int i=n-1;i;--i)
			{
				if(s[i]==s[i+1]) nxt[i]=nxt[i+1];
				else nxt[i]=i+1; 
			}
			for(int i=1;i<n;++i)
			{
				if(s[i+1]>s[i])
				{
					pos=i;break;
				}
				if(s[i+1]==s[i])
				{
					if(s[pre[i]]<=s[nxt[i]])
					{
						if(!pre[i]){pos=i;break;}
						else
						{
							pos=nxt[i]-1;break;
						}
					}
				}
			}
			for(int i=1;i<=pos;++i) putchar(s[i]);
			for(int i=pos;i;--i) putchar(s[i]);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
1
5
dcccb

*/