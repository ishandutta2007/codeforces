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
	const int N=3e5+10;
	int haku;
	int n;
	int a[N],b[N];
	bool f1,f2,f;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();f1=f2=f=0;
			for(int i=1;i<=n;++i) a[i]=read();
			for(int i=1;i<=n;++i) b[i]=read();
			for(int i=1;i<=n;++i)
			{
				if(b[i]>a[i]&&!f1){f=1;break;}
				if(b[i]<a[i]&&!f2){f=1;break;}
				if(a[i]==1) f1=1;
				if(a[i]==-1) f2=1;
			}
			puts(f?"NO":"YES");
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
3
1 -1 0
1 1 -2

*/