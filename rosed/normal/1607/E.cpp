#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-12)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=2e6+10,mod=998244353;
	int T,n,m,len;
	int posx,posy;
	char s[N];
	int dx,dy;
	int maxx,minx,maxy,miny;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();
			cin>>(s+1);
			len=strlen(s+1);
			maxx=maxy=minx=miny=0;
			posx=posy=1;
			dx=dy=0;
			for(int i=1;i<=len;++i)
			{
				if(s[i]=='L') --dy;
				if(s[i]=='R') ++dy;
				if(s[i]=='U') --dx;
				if(s[i]=='D') ++dx;
				maxx=max(maxx,dx),minx=min(minx,dx);
				maxy=max(maxy,dy),miny=min(miny,dy);
				if(maxx-minx+1<=n&&maxy-miny+1<=m) posx=-minx+1,posy=-miny+1;
				else break;
			}
			printf("%lld %lld\n",posx,posy);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}