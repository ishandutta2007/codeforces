#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=5e5+10,mod=998244353;
	int T,n;
	char s[N];
	int cnt[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			cin>>(s+1);
			n=strlen(s+1);
			for(int i=0;i<26;++i) cnt[i]=0;
			for(int i=1;i<=n;++i) ++cnt[s[i]-'a'];
			for(int i=0;i<26;++i)
			{
				if(cnt[i]==2) putchar(i+'a');
			}
			for(int i=0;i<26;++i)
			{
				if(cnt[i]==1) putchar(i+'a');
			}
			for(int i=0;i<26;++i)
			{
				if(cnt[i]==2) putchar(i+'a');
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
/*
1
6 2
bfvfbv

*/