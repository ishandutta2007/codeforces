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
	int T,n,m;
	char a[N],b[N];
	int vis[250];
	int num;
	inline void main()
	{
		T=read();
		while(T--)
		{
			cin>>(a+1)>>(b+1);
			n=strlen(a+1);
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=n;++i) ++vis[a[i]-'a'];
			num=vis[0];
			while(vis[0]--) printf("a");
			if(b[1]=='a'&&b[2]=='b'&&num)
			{
				while(vis[2]--) printf("c");
				while(vis[1]--) printf("b");
			}
			else
			{
				while(vis[1]--) printf("b");
				while(vis[2]--) printf("c");
			}
			for(int i=3;i<26;++i)
			{
				while(vis[i]--) putchar(i+'a');
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

*/